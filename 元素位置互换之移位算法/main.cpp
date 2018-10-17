/****************************************
本题必须用线性表而不能用链表，因为会MTL
*****************************************/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define maxsize 1000001
using namespace std;

typedef struct
{
    int *elem;
    int lenth;
    int lengthsize;
} Sqlist;

void InitSqlist(Sqlist &l)
{
    l.elem = (int *)malloc(maxsize * sizeof(int));
    if(!l.elem)
    {
        exit(0);
    }

    l.lenth = 0;
    l.lengthsize = maxsize;
}

void creat_list(Sqlist &l, int len)
{
    int i;
    l.lenth = len;

    for(i = 1; i <= len; i++)
    {
        scanf("%d", &l.elem[i]);
    }

}

void change_list(Sqlist &l, int s, int h, int m)
{
    int i, t;

    for(i = 1; i <= m; i++)
    {
        t = l.elem[s];
        l.elem[s++] = l.elem[h];
        l.elem[h--] = t;
    }
}

void print_list(Sqlist &l, int len)
{
    for(int i = 1; i <= len; i++)
    {
        printf("%d%c", l.elem[i], i == len? '\n' : ' ');
    }
}

int main(void)
{
    int len, t, m;
    Sqlist l;
    scanf("%d", &len);
    InitSqlist(l);
    creat_list(l, len);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &m);
        change_list(l, 1, len, len / 2);
        change_list(l, 1, len - m, (len - m) / 2);
        change_list(l, len - m + 1, len,  m / 2);

        print_list(l, len);

    }

    return 0;
}
