#include <stdio.h>
#include "interpret.h"          
#include "stack.h"               

static void repl()
{
  stack_init();
  char line[1024]; 
  
  for (;;)                              
  {
    printf("> ");                       
    
    if (!fgets(line, sizeof(line), stdin))       
    {
      printf("\n");                      
      break;
    }

    interpret(line);                     
  }
}

int main () 
{
  repl();
  return 0;
}

