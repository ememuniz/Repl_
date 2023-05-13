#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "interpret.h"
#include "stack.h"

Stack *s;

void stack_init () 
{
  s = new_stack(20);
}

void interpret (const char *source) 
{                
    char op[10];
    char arg[10];
  
    sscanf (source, "%s%s", op, arg);                        
    //printf("operação: %s\n", op);
    //printf("argumento: %s\n",  arg);

    if ( strcmp (op, "push") == 0)                     
    {                       
      int x = atoi(arg);                                   
      stack_push(s, x);      
    } 
    else if ( strcmp (op, "div") == 0) 
    {  
        int x = stack_pop(s);    
        int y = stack_pop(s);  
        stack_push(s, y / x);    
    } 
    else if (strcmp(op,"add") == 0) 
    {
      int x= stack_pop(s);
      int y= stack_pop(s);
      stack_push(s,x+y);
    } 
    else if (strcmp(op,"mult")==0)
    {
      int x= stack_pop(s);
      int y= stack_pop(s);
      stack_push(s,x*y);
    }
    else if (strcmp(op,"sub")==0)
    {
      int x= stack_pop(s);
      int y= stack_pop(s);
      stack_push(s, y-x);
    }
    else if (strcmp(op,"print")==0)
    {
      printf("%d\n",stack_pop(s));
    }
  
}