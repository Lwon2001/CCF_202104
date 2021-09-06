//
// Created by Administrator on 2021/9/5.
//
#include<stdio.h>
#include<malloc.h>
#include<mem.h>

int main()
{
    int n,m,l;
    int i;
    scanf("%d %d %d\n", &n, &m, &l);
    int temp;
    int *h = (int *)malloc(sizeof(int) * l);
    memset(h, 0 , sizeof(int) * l);
    while(n--)
    {
        for(i = 0; i < m; i++)
        {
            scanf("%d", &temp);
            h[temp]++;
        }
    }
    for(i = 0; i < l; i++)
    {
        printf("%d ",h[i]);
    }
    return 0;
}
