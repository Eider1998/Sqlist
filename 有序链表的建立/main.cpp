#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*head;

void creat_list(int n)
{
    struct node *p, *tail;
    tail = head;

    for(int i = 0; i < n; i++)
    {
        p = (node *)malloc(sizeof(node));
        p-> next = NULL;

        scanf("%d", &p-> data);
        tail-> next = p;
        tail = p;
    }
}

void pai_list(int n)
{
   struct node *p, *q;
   int t;
   for(p = head-> next; p-> next != NULL; p = p-> next)
   {
       for(q = p-> next; q != NULL; q = q-> next)
       {
           if(p-> data > q-> data)
           {
               t = p-> data;
               p-> data = q-> data;
               q-> data = t;
           }
       }
   }

}

void print_list()
{
    struct node *p;
    p = head-> next;

    while(p)
    {
        if(p-> next != NULL)
        {
            printf("%d ", p-> data);
        }

        else
        {
            printf("%d\n", p-> data);
        }

        p = p-> next;
    }
}
int main(void)
{
    int n;

    head = (node *)malloc(sizeof(node));
    head-> next = NULL;
    scanf("%d", &n);
    creat_list(n);
    pai_list(n);
    print_list();

    return 0;
}
