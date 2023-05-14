#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "interpret.h"
#include "stack.h"
#define N 100

typedef struct stack 
{
  int *elements;
  int top; 
}Stack;
                                              
Stack* new_stack(int size) 
{
  Stack* s=(Stack*) malloc(sizeof(Stack));
  s->elements=(int*) malloc(sizeof(Stack));
  s->top=0;
  return s;
}

void stack_push(Stack* s, int value)  
{
  s->elements[s->top++]= value;
}

int stack_pop (Stack* s) 
{
  return s->elements[--s->top];
}

void stack_print(Stack* s)
{
  for(int i=s->top-1;i>=0;i--)
    {
      printf("%d\n",s->elements[i]);
    }
}
