#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#define maxsize 100001
using namespace std;

int count = 0;
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

int sum_list(Sqlist &l, int x, int y)
{
    count++;
    int t1, t, sum1 = 0, i, sum2 = 0, sum3 = 0, sum4 = 0, mid, ans1 = 0, ans2 = 0;
    mid = (x + y) / 2;
    if(x >= y)
    {
        if(l.elem[x] > 0)
        {
            return l.elem[x];
        }

        else
        {
            return 0;
        }
    }

    else
    {
        sum1 = sum_list(l, x, mid);
        sum2 = sum_list(l, mid + 1, y);

        for(i = mid; i >= x; i--)
        {
            sum3 += l.elem[i];
            ans1 = max(sum3, ans1);
        }

        for(i = mid + 1; i <= y; i++)
        {
            sum4 += l.elem[i];
            ans2 = max(sum4, ans2);
        }

        t = sum1;
        if(sum1 < sum2)
        {
            t = sum2;
        }

        t1 = ans1 + ans2;

        if(t1 > t)
        {
            return t1;
        }

        if(t1 < t)
        {
            return t;
        }
    }


}
int main(void)
{
    int n, sum = 0;
    Sqlist l;

    scanf("%d", &n);
    InitSqlist(l);
    creat_list(l, n);
    sum = sum_list(l, 0, n - 1);
    printf("%d %d\n", sum, count);

    return 0;
}
