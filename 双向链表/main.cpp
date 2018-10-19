#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *front, *next;

}*head;

void creat_list(int n)
{
    struct node *p, *tail;

    tail = head;
    for(int i = 0; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p-> next = NULL;
        p-> front = NULL;

        scanf("%d", &p-> data);
        tail-> next = p;
        p-> front = tail;
        tail = p;
    }

}

void find_list(int x)
{
    struct node *p;
    p = head-> next;

    while(p)
    {
        if(p-> data == x)
        {
            if(p-> next != NULL && p-> front != head)
            {
                printf("%d %d\n", p-> front-> data, p-> next-> data);
            }

            else if(p-> next == NULL)
            {
                printf("%d\n", p-> front-> data);
            }

            else if(p-> front == head)
            {
                printf("%d\n", p-> next-> data);
            }
        }
             p = p-> next;
    }
}

int main(void)
{
    int n, m, i, x;

    head = (struct node *)malloc(sizeof(struct node));
    head-> next = NULL;
    head->front = NULL;

    scanf("%d %d", &n, &m);
    creat_list(n);

    for(i = 0; i < m; i++)
    {
        scanf("%d", &x);

        find_list(x);
    }
}
