#include <stdlib.h>
#include <stdio.h>

typedef enum{
STACK_FULL=0,
STACK_EMPTY,
STACK_DONE
}stack_status_t;

typedef struct{
int *dataArr;
int sp;
int stackSize;
}stack_t;

typedef stack_t* STACK_T;

stack_t* stack_delete(stack_t* stack);
stack_t* stack_create(int size);
stack_status_t push(stack_t *stack,int data);
stack_status_t pop(stack_t *stack,int*pdata);



