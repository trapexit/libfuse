VERSION = "3.4.0"
OPT = -O2

DESTDIR = "/"
BINDIR = "/bin"
SRC   = lib/buffer.c \
	lib/cuse_lowlevel.c \
	lib/fuse.c \
	lib/fuse_loop.c \
	lib/fuse_loop_mt.c \
	lib/fuse_lowlevel.c \
	lib/fuse_opt.c \
	lib/fuse_signals.c \
	lib/helper.c \
	lib/mount.c \
	lib/mount_util.c
OBJ  = $(SRC:lib/%.c=obj/%.o)
DEPS = $(OBJ:obj/%.o=obj/%.d)
CFLAGS = $(OPT) \
	 -g \
	 -Wall \
	 -pipe \
	 '-D_FILE_OFFSET_BITS=64' \
	 '-D_REENTRANT' \
	 '-DFUSE_USE_VERSION=34' \
	 '-DFUSERMOUNT_DIR="/usr/local/bin"' \
	 '-DPACKAGE_VERSION=$(VERSION)' \
         '-DFUSE_CONF="/usr/local/etc/fuse.conf"' \
	 -Iinclude \
	 -MMD

all: obj/libfuse.a mergerfs-mount mount.mergerfs

include/config.h:
	tools/build-config_h | tee include/config.h

obj/libfuse.a: obj/obj-stamp include/config.h $(OBJ)
	ar rcs obj/libfuse.a $(OBJ)

mergerfs-mount: include/config.h util/fusermount.c lib/mount_util.c
	$(CC) $(CFLAGS) -Ilib -o mergerfs-mount util/fusermount.c lib/mount_util.c

mount.mergerfs: obj/libfuse.a util/mount.fuse.c
	$(CC) $(CFLAGS) -o mount.mergerfs util/mount.fuse.c obj/libfuse.a -ldl -pthread

obj/obj-stamp:
	mkdir -p obj
	touch $@

obj/%.o: lib/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj include/config.h mergerfs-mount mount.mergerfs

distclean: clean

install:
	install -D mergerfs-mount "$(DESTDIR)$(BINDIR)/mergerfs-mount"
	chown root:root "$(DESTDIR)$(BINDIR)/mergerfs-mount"
	chmod u+s "$(DESTDIR)$(BINDIR)/mergerfs-mount"
	install -D mount.mergerfs "$(DESTDIR)$(BINDIR)/mount.mergerfs"
