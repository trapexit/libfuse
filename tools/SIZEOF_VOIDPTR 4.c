#include "static_assert.h"

int
main(int   argc,
     char *argv[])
{
  STATIC_ASSERT(sizeof(void*) == 4,sizeof_voidptr);

  return 0;
}
