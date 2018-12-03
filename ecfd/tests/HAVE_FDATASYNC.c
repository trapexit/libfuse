#include <unistd.h>

int
main(int   argc,
     char *argv[])
{
  (void)fdatasync;

  return 0;
}
