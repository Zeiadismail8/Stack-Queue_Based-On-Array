#include "stack.h"

stack_t* stack_create(int size)
{
    stack_t* s=malloc(sizeof(stack_t));
    s->dataArr=malloc(size*sizeof(int));
    s->sp=0;
    s->stackSize=size;
    return s;
}

stack_t* stack_delete(stack_t* stack)
{
    free(stack->dataArr);
    stack->dataArr=0;
    free(stack);
    return 0;
}

stack_status_t push(stack_t *stack,int data)
{
    stack_status_t statusLoc=STACK_DONE;
    if(stack->sp==stack->stackSize)
    {
        statusLoc=STACK_FULL;
    }
    else
    {
        stack->dataArr[stack->sp]=data;
        stack->sp++;
    }
    return statusLoc;
}

stack_status_t pop(stack_t *stack,int*pdata)
{
    stack_status_t statusLoc=STACK_DONE;
    if(stack->sp==0)
    {
        statusLoc=STACK_EMPTY;
    }
    else
    {
        stack->sp--;
        *pdata=stack->dataArr[stack->sp];
    }
    return statusLoc;
}
