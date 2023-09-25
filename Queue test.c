#include "Queue.h"

int main()
{
    int x,n,y;

    QUEUE_T q1,q2;

    q1=Queue_create(4);
    q2=Queue_create(2);

    while(1)
    {
        printf("\033[33mEnter Queue number you want : \033[0m");
        scanf("%d",&n);


        if(n==1)
        {
            printf("\033[33mEnter\033[0m \033[36m0\033[0m \033[33mif you want dequeue or\033[0m \033[36m1\033[0m \033[33mif you want enqueue : \033[0m");
            scanf("%d",&x);

            if(x==1)
            {
                printf("\033[33mEnter number you want add in Queue 1 : \033[0m");
                scanf("%d",&y);
                if(enqueue2(q1,y)==QUEUE_FULL)
                {
                    printf("\033[31mQueue full\033[0m\a\n\n");
                }
                else
                {
                    printf("\033[32m%d   enqueue\033[0m\n\n",y);
                }
            }
            else if(x==0)
            {
                if(dequeue2(q1,&y)==QUEUE_EMPTY)
                {
                    printf("\033[31mQueue empty\033[0m\a\n\n");
                }
                else
                {
                    printf("\033[32m%d   dequeue\033[0m\n\n",y);
                }
            }
            else
            {
                printf("\033[31mInvalid Input\n\033[0m");
            }
        }
        else if(n==2)
        {
            printf("\033[33mEnter\033[0m \033[36m0\033[0m \033[33mif you want dequeue or\033[0m \033[36m1\033[0m \033[33mif you want enqueue : \033[0m");
            scanf("%d",&x);

            if(x==1)
            {
                printf("\033[33mEnter number you want add in Queue 1 : \033[0m");
                scanf("%d",&y);
                if(enqueue2(q2,y)==QUEUE_FULL)
                {
                    printf("\033[31mQueue full\033[0m\a\n\n");
                }
                else
                {
                    printf("\033[32m%d   enqueue\033[0m\n\n",y);
                }
            }
            else if(x==0)
            {
                if(dequeue2(q2,&y)==QUEUE_EMPTY)
                {
                    printf("\033[31mQueue empty\033[0m\a\n\n");
                }
                else
                {
                    printf("\033[32m%d   dequeue\033[0m\n\n",y);
                }
            }
            else
            {
                printf("\033[31mInvalid Input\n\033[0m");
            }
        }
        else
        {
            printf("\033[31mNOT FOUND THIS QUEUE\n\033[0m");
        }
    }
    return 0;
}

