#include "stack.h"

int main()
{
    int x,n;

    STACK_T s1,s2;

    s1=stack_create(20);
    s2=stack_create(50);

    while(1)
    {
        printf("Enter number of stack you want : ");
        scanf("%d",&n);
        scanf("%d",&x);
        if(n==1)
        {
            if(x!=0)
            {
                if(push(s1,x)==STACK_FULL)
                {
                    printf("stack full\n");
                }
                else
                {
                    printf("%d is pushed\n",x);
                }
            }
            else
            {
                if(pop(s1,&x)==STACK_EMPTY)
                {
                    printf("stack empty\n");
                }
                else
                {
                    printf("data is %d\n",x);
                }
            }


        }
        else if(n==2)
        {
            if(x!=0)
            {
                if(push(s2,x)==STACK_FULL)
                {
                    printf("stack full\n");
                }
                else
                {
                    printf("%d is pushed\n",x);
                }
            }
            else
            {
                if(pop(s2,&x)==STACK_EMPTY)
                {
                    printf("stack empty\n");
                }
                else
                {
                    printf("data is %d\n",x);
                }
            }
        }
        else
        {
            printf("NOT FOUND THIS STACK\n");
        }
    }

    return 0;
}

