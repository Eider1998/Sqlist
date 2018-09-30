
#include<stdio.h>
#include<malloc.h>
struct node
{
    int number;
    struct node* next;
};
struct node* Create(int num)
{
    struct node* head,*p;
    head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    for(int i=0;i<num;i++)
    {
        p=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&p->number);
        p->next=head->next;
        head->next=p;
    }
    return head;
};

void shuchu(struct node*head)
{
    struct node *p;
    p=head->next;
    while(p)
    {
        if(p==head->next)
            printf("%d",p->number);
        else
            printf(" %d",p->number);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    int n;
    struct node *head;
    scanf("%d",&n);
    head=Create(n);
    //printf("%d\n",n);
    shuchu(head);

    return 0;
}
