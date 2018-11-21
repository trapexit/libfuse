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
	 -Iinclude \
	 -MMD

all: libmffl.a

include/config.h:
	tools/build-config_h | tee include/config.h

libmffl.a: obj/obj-stamp include/config.h $(OBJ)
	ar rcs obj/libmffl.a $(OBJ)

obj/obj-stamp:
	mkdir -p obj
	touch $@

obj/%.o: lib/%.c
	$(CC) $(OPT) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj include/config.h

distclean: clean
