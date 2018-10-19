#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int a = 0, b = 0;

struct node
{
    int data;
    struct node *next;
}*head1, *head2;

void creat_list(int n)
{
    struct node *p, *tail1, *tail2;

    //head = (node *)malloc(sizeof(node));
    head1 = (node *)malloc(sizeof(node));
    head2 = (node *)malloc(sizeof(node));

    //head-> next = NULL;
    head1-> next = NULL;
    head2-> next = NULL;
    tail1 = head1;
    tail2 = head2;
    for(int i = 0; i < n; i++)
    {
        p = (node *)malloc(sizeof(node));
        p-> next = NULL;

        scanf("%d", &p-> data);
        if(p-> data % 2 == 0)
        {
            tail1-> next = p;
            tail1 = p;
            a++;
        }

        else
        {
            tail2-> next = p;
            tail2 = p;
            b++;
        }
    }
}

void print_list(struct node *head)
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
    scanf("%d", &n);
    creat_list(n);
    printf("%d %d\n", a, b);
    print_list(head1);
    print_list(head2);

    return 0;
}
