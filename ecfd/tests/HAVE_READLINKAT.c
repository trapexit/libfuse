#include <fcntl.h>
#include <unistd.h>

int
main(int   argc,
     char *argv[])
{
  (void)readlinkat;

  return 0;
}
