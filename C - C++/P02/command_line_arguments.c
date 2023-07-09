//
// Tomás Oliveira e Silva, AED, October 2021
//
// list all command line arguments
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[argc])
{
  char str[100];

  for(int i = 0;i < argc;i++)
    printf("argv[%2d] = \"%s\"\n %2d",i,argv[i]);
  return 0;
}
