VERSION = "3.4.0"
OPT = -O2

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

all: obj/libmffl.a mergerfs-mount mount.mergerfs

include/config.h:
	tools/build-config_h | tee include/config.h

obj/libmffl.a: obj/obj-stamp include/config.h $(OBJ)
	ar rcs obj/libmffl.a $(OBJ)

mergerfs-mount: include/config.h util/fusermount.c lib/mount_util.c
	$(CC) $(OPT) $(CFLAGS) -Ilib -o mergerfs-mount util/fusermount.c lib/mount_util.c

mount.mergerfs: obj/libmffl.a util/mount.fuse.c
	$(CC) $(OPT) $(CFLAGS) -o mount.mergerfs util/mount.fuse.c obj/libmffl.a -ldl -pthread

obj/obj-stamp:
	mkdir -p obj
	touch $@

obj/%.o: lib/%.c
	$(CC) $(OPT) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj include/config.h mergerfs-mount mount.mergerfs

distclean: clean
