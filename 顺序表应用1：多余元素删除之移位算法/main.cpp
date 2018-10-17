#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


typedef struct
{
    int data[10001];
    int lenthsize;
}list;

void InitList(list &l)
{
    l.lenthsize  = 0;
}

void build_list(list &l, int m)
{
    int i;
    l.lenthsize = m;

    for(i = 0; i < m; i++)
    {
        scanf("%d", &l.data[i]);
    }
}

void delete_list(list &l)
{
    int i, j, k;

    for(i = 0; i < l.lenthsize - 1; i++)
    {
        for(j = i + 1; j < l.lenthsize; j++)
        {
            if(l.data[i] == l.data[j])
            {
                for(k = j; k < l.lenthsize - 1; k++)
                {
                    l.data[k] = l.data[k + 1];
                }
                l.lenthsize--;
                j--;
            }
        }
    }
}

void print_list(list &l)
{
    int i;
    for(i = 0; i < l.lenthsize; i++)
    {
        printf("%d%c", l.data[i], i == l.lenthsize - 1 ? '\n' : ' ');
    }
}

int main(void)
{
    int n, m;

    scanf("%d", &n);
    while(n--)
    {
        list l;
        InitList(l);
        scanf("%d", &m);
        build_list(l, m);
        delete_list(l);
        print_list(l);
    }

    return 0;
}
