#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define maxsize 100001
using namespace std;

typedef struct
{
    int *elem;
    int len;
    int listsize;
} Sqlist;

void InitSqlist(Sqlist &l)
{
    l.len = 0;
    l.listsize = maxsize;

    l.elem = (int *)malloc(maxsize * sizeof(int));
    if(!l.elem)
    {
        exit(0);
    }
}

void creat_list(Sqlist &l, int n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &l.elem[i]);
    }
}

int find_num(Sqlist &l, int x, int q, int r)
{
    if(q > r)
    {
        return -1;
    }

    while(q <= r)
    {
        int mid = (q + r) / 2;

        if(l.elem[mid] == x)
        {
            return mid + 1;
        }

        else if(l.elem[mid] > x)
        {
            return find_num(l, x, q, mid - 1);
        }

        else if(l.elem[mid] < x)
        {
            return find_num(l, x, mid + 1, r);
        }

    }

    return -1;

}

int main(void)
{
    int n, t, x, i, m;
    Sqlist l;

    scanf("%d", &n);
    InitSqlist(l);
    creat_list(l, n);
    scanf("%d", &t);

    for(i = 0; i < t; i++)
    {
        scanf("%d", &x);
        m = -1;
        m = find_num(l, x, 0, n - 1);

        if(m == -1)
        {
            printf("No Found!\n");
        }

        else
        {
            printf("%d\n", m);
        }
    }

    return 0;
}
