#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node
{
    int a, b;
    struct node *next;
}*p;

void creat_list(int n)
{
    struct node *q, *tail, *x, *x1;
    int i;

    p = (node *)malloc(sizeof(node));
    q = (node *)malloc(sizeof(node));

    p-> a = 0;
    p-> b = 1;
    q-> a = 1;
    q-> b = 1;

    p-> next = q;
    q-> next = NULL;

    for(i = 2; i <= n; i++)
    {
        x = p;
        tail = x-> next;

        while(tail)
        {
            if(x-> b + tail-> b <= n)
            {
                x1 = (node *)malloc(sizeof(node));
                x1-> a = x-> a + tail-> a;
                x1-> b = x-> b + tail-> b;

                x1-> next = tail;
                x-> next = x1;
            }

            x = x-> next;
            tail = x-> next;
        }
    }
}

void print(struct node *p)
{
    struct node *q;
    int i = 1;
    q = p;

    while(q)
    {
        if(i % 10 != 0)
        {
            printf("%d/%d\t", q-> a, q-> b);
            i++;
        }

        else
        {
            printf("%d/%d\n", q-> a, q-> b);
            i++;
        }

        q = q-> next;
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    creat_list(n);
    print(p);

    return 0;
}
