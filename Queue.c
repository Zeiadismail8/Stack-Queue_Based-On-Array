#include "Queue.h"


QUEUE_T Queue_create(int size)
{
    Queue_t* s=malloc(sizeof(Queue_t));
    s->dataArr=malloc(size*sizeof(int));
    s->qp_in=0;
    s->qp_out=0;
    s->QueueSize=size;
    s->Count=0;
    return s;
}

QUEUE_T Queue_delete(QUEUE_T Queue)
{
    free(Queue->dataArr);
    Queue->dataArr=0;
    free(Queue);
    return 0;
}


Queue_status_t enqueue(QUEUE_T Queue,int data)
{
    Queue_status_t statusLoc=QUEUE_DONE;

    if( Queue->qp_in == Queue->QueueSize )
    {
        statusLoc=QUEUE_FULL;
    }
    else
    {
        if( (Queue->qp_in==Queue->qp_out) && (Queue->Count==0) )
        {
            Queue->qp_in =0;
            Queue->qp_out=0;

            Queue->dataArr[Queue->qp_in]=data;
            Queue->qp_in++;
            Queue->Count++;
        }
        else if( (Queue->qp_in==Queue->qp_out) && (Queue->Count=Queue->QueueSize) )
        {
            statusLoc=QUEUE_FULL;
        }
        else if( (Queue->qp_in == Queue->QueueSize) && (Queue->qp_out!=0) )
        {
            Queue->qp_in=0;

            Queue->dataArr[Queue->qp_in]=data;
            Queue->qp_in++;
            Queue->Count++;
        }
        else if( (Queue->qp_in == Queue->QueueSize) && (Queue->qp_out==0) )
        {
            Queue->qp_in=0;

            statusLoc=QUEUE_FULL;
        }
        else if( Queue->qp_in!=Queue->qp_out )
        {
            Queue->dataArr[Queue->qp_in]=data;
            Queue->qp_in++;
            Queue->Count++;
        }
    }
    return statusLoc;
}

Queue_status_t dequeue(QUEUE_T Queue,int*pdata)
{
    Queue_status_t statusLoc=QUEUE_DONE;

    if( (Queue->qp_out==Queue->qp_in) && (Queue->Count==0) )
    {
        statusLoc=QUEUE_EMPTY;
    }
    else if( (Queue->qp_out==Queue->qp_in) && (Queue->Count=Queue->QueueSize) )
    {
        if(Queue->qp_out==Queue->QueueSize)
        {
            *pdata=Queue->dataArr[Queue->qp_out];
            Queue->qp_out=0;
            Queue->Count--;
        }
        else
        {
            *pdata=Queue->dataArr[Queue->qp_out];
            Queue->qp_out++;
            Queue->Count--;
        }
    }
    else if( (Queue->qp_out == Queue->QueueSize) )
    {
        *pdata=Queue->dataArr[Queue->qp_out];
        Queue->qp_out=0;
        Queue->Count--;
    }
    else if( Queue->qp_out!=Queue->qp_in )
    {

        *pdata=Queue->dataArr[Queue->qp_out];
        Queue->qp_out++;
        Queue->Count--;

        if( (Queue->qp_out==Queue->QueueSize) && (Queue->qp_in==Queue->QueueSize))
        {
            Queue->qp_out=0;
            Queue->qp_in=0;
        }
    }
    return statusLoc;
}

Queue_status_t enqueue2(QUEUE_T Queue,int data)
{
    Queue_status_t statusLoc=QUEUE_DONE;


    if( Queue->qp_in == Queue->QueueSize )
    {
        statusLoc=QUEUE_FULL;
    }
    else
    {
        Queue->dataArr[Queue->qp_in]=data;
        Queue->qp_in++;
        Queue->Count++;
    }
    return statusLoc;
}


Queue_status_t dequeue2(QUEUE_T Queue,int*pdata)
{
    Queue_status_t statusLoc=QUEUE_DONE;

    if(Queue->qp_in == 0)
    {
        statusLoc=QUEUE_EMPTY;
    }
    else
    {
        *pdata=Queue->dataArr[0];

        for(int i=0; i<(Queue->Count)-1; i++)
        {
            Queue->dataArr[i]=Queue->dataArr[i+1];
        }

        Queue->qp_in--;
        Queue->Count--;
    }
    return statusLoc;
}
