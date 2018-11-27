#include "fuse_lowlevel.h"

void
fuse_lowlevel_op_init(void		    *userdata_,
		      struct fuse_conn_info *conn_)
{

}

void
fuse_lowlevel_op_destroy(void *userdata_)
{

}

void
fuse_lowlevel_op_lookup(fuse_req_t  req_,
                        fuse_ino_t  parent_,
                        const char *name_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_forget(fuse_req_t req_,
                        fuse_ino_t ino_,
                        uint64_t   nlookup_)
{
  fuse_reply_none(req_);
}

void
fuse_lowlevel_op_getattr(fuse_req_t             req_,
                         fuse_ino_t             ino_,
                         struct fuse_file_info *ffi_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_setattr(fuse_req_t             req_,
                         fuse_ino_t             ino_,
                         struct stat           *attr_,
                         int                    to_set_,
                         struct fuse_file_info *ffi_)
{
  fuse_reply_err(req,ENOSYS);
}

void
fuse_lowlevel_op_readlink(fuse_req_t req_,
                          fuse_ino_t ino_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_mknod(fuse_req_t  req_,
                       fuse_ino_t  parent_,
                       const char *name_,
                       mode_t      mode_,
                       dev_t       rdev_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_mkdir(fuse_req_t  req_,
                       fuse_ino_t  parent_,
                       const char *name_,
                       mode_t      mode_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_unlink(fuse_req_t  req_,
                        fuse_ino-t  parent_,
                        const char *name_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_rmdir(fuse_req_t  req_,
                       fuse_ino_t  parent_,
                       const char *name_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_symlink(fuse_req_t  req_,
                         const char *link_,
                         fuse_ino_t  parent_,
                         const char *name_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_rename(fuse_req_t    req_,
                        fuse_ino_t    parent_,
                        const char   *name_,
                        fuse_ino_t    newparent_,
                        const char   *newname_,
                        unsigned int  flags_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_link(fuse_req_t  req_,
                      fuse_ino_t  ino_,
                      fuse_ino_t  newparent_,
                      const char *newname_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_open(fuse_req_t             req_,
                      fuse_ino_t             ino_,
                      struct fuse_file_info *ffi_)
{
  fuse_reply_open(req_,ffi_);
}

void
fuse_lowlevel_op_read(fuse_req_t             req_,
                      fuse_ino_t             ino_,
                      size_t                 size_,
                      off_t                  off_,
                      struct fuse_file_info *ffi_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_write(fuse_req_t             req_,
                       fuse_ino_t             ino_,
                       const char            *buf_,
                       size_t                 size_,
                       off_t                  off_,
                       struct fuse_file_info *ffi_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_flush(fuse_req_t             req_,
                       fuse_ino_t             ino_,
                       struct fuse_file_info *ffi_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_release(fuse_req_t             req_,
                         fuse_ino_t             ino_,
                         struct fuse_file_info *ffi_)
{
  fuse_reply_err(req_,0);
}

void
fuse_lowlevel_op_fsync(fuse_req_t             req_,
                       fuse_ino_t             ino_,
                       int                    datasync_,
                       struct fuse_file_info *ffi_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_opendir(fuse_req_t             req_,
                         fuse_ino_t             ino_,
                         struct fuse_file_info *ffi_)
{
  fuse_reply_open(req_,ffi_);
}

void
fuse_lowlevel_op_readdir(fuse_req_t             req_,
                         fuse_ino_t             ino_,
                         size_t                 size_,
                         off_t                  off_,
                         struct fuse_file_info *ffi_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_releasedir(fuse_req_t             req_,
                            fuse_ino_t             ino_,
                            struct fuse_file_info *ffi_)
{
  fuse_reply_err(req_,0);
}

void
fuse_lowlevel_op_fsyncdir(fuse_req_t             req_,
                          fuse_ino_t             ino_,
                          int                    datasync_,
                          struct fuse_file_info *ffi_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_statfs(fuse_req_t req_,
                        fuse_ino_t ino)
{
  struct statvfs buf = {0};

  buf.f_namemax = 255;
  buf.f_bsize   = 512;
  fuse_reply_statfs(req_,&buf);
}

void
fuse_lowlevel_op_setxattr(fuse_req_t  req_,
                          fuse_ino_t  ino_,
                          const char *name_,
                          const char *value_,
                          size_t      size_,
                          int         flags_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_getxattr(fuse_req_t  req_,
                          fuse_ino_t  ino_,
                          const char *name_,
                          size_t      size_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_listxattr(fuse_req_t req_,
                           fuse_ino_t ino_,
                           size_t     size_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_removexattr(fuse_req_t  req_,
                             fuse_ino_t  ino_,
                             const char *name_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_access(fuse_req_t req_,
                        fuse_ino-t ino_,
                        int        mask_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_create(fuse_req_t             req_,
                        fuse_ino_t             parent_,
                        const char            *name_,
                        mode_t                 mode_,
                        struct fuse_file_info *ffi_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_getlk(fuse_req_t             req_,
                       fuse_ino_t             ino_,
                       struct fuse_file_info *ffi_,
                       struct flock          *lock_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_setlk(fuse_req_t             req_,
                       fuse_ino_t             ino_,
                       struct fuse_file_info *ffi_,
                       struct flock          *lock_,
                       int                    sleep_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_bmap(fuse_req_t req_,
                      fuse_ino_t ino_,
                      size_t     blocksize_,
                      uint64_t   idx_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_ioctl(fuse_req_t             req_,
                       fuse_ino_t             ino_,
                       int                    cmd_,
                       void                  *arg_,
                       struct fuse_file_info *ffi_,
                       unsigned               flags_,
                       const void            *in_buf_,
                       size_t                 in_bufsz_,
                       size_t                 out_bufsz_)
{
  fuse_reply_err(req_,ENOSYS);
}

void
fuse_lowlevel_op_poll(fuse_req_t              req_,
                      fuse_ino_t              ino_,
                      struct fuse_file_info  *ffi_,
                      struct fuse_pollhandle *ph_)
{
  fuse_reply_err(req,ENOSYS);
}
