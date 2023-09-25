#include <stdlib.h>
#include <stdio.h>

typedef enum{
QUEUE_FULL=0,
QUEUE_EMPTY,
QUEUE_DONE
}Queue_status_t;

typedef struct{
int *dataArr;
int qp_in;
int qp_out;
int QueueSize;
int Count;
}Queue_t;

typedef Queue_t* QUEUE_T;

QUEUE_T Queue_delete(QUEUE_T Queue);
QUEUE_T Queue_create(int size);

Queue_status_t enqueue(QUEUE_T Queue,int data);
Queue_status_t dequeue(QUEUE_T Queue,int*pdata);

Queue_status_t enqueue2(QUEUE_T Queue,int data);
Queue_status_t dequeue2(QUEUE_T Queue,int*pdata);
