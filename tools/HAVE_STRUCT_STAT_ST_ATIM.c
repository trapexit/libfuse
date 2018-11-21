#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int
main(int   argc,
     char *argv[])
{
  struct stat st;

  st.st_atim;
  
  return 0;
}
