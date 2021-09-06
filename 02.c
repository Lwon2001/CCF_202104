#include<stdio.h>
#include<malloc.h>


int main()
{
    int n, L, r, t;
    int row, col;  //循环用
    int row_start, row_end, col_start, col_end;
    int i, j;  //循环用
    int answer = 0;
    int count;  //计算每次的neighb和的像素点的个数
    double neighbor = 0;  // 某一个点的neighbor和
    double average;
    scanf("%d %d %d %d\n", &n, &L, &r, &t);
    /* 创建二维数组存入数据 */
    int **matrix = (int **)malloc(sizeof(int *) * n);
    for(i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * n);
    }
    for(i =0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(i = 0; i < n; i++)
    {
        neighbor = 0;
        int first_end_flag = 0;  //第一次范围触底matrix最后一列，在这之后neighbor值不再增加
        row_start = 0 > i - r ? 0 : i - r;
        row_end = n - 1  < i + r ? n - 1 : i + r;
        for(j = 0; j < n; j++)
        {
            col_start = 0 > j - r ? 0 : j - r;
            col_end = n - 1  < j + r ? n - 1 : j + r;
            if(j == 0)  // 每行第一个元素进行计完整计算，此后的计算都利用上一次计算的值
            {
                count = 0;  // count 记录遍历的像素数
                for(row = row_start; row <= row_end; row++)
                {
                    for(col = col_start; col <= col_end; col++)
                    {
                        neighbor += matrix[row][col];
                        count++;
                    }
                }
            }
            else
            {
                for(row = row_start; row <= row_end; row++)
                {
                    if(col_start > 0)  //现在列开头大于等于1，也就是说比上一次计算neighbor要少一列
                    {
                        neighbor -= matrix[row][col_start - 1];
                        count--;
                    }
                    if(first_end_flag == 0 && col_end < n)  //现在列尾不是最后一列或者第一次为最后一列，则neighbor加上最后一列的值
                    {
                        neighbor += matrix[row][col_end];
                        count++;
                        if(col_end == n - 1 && row == row_end)
                        {
                            first_end_flag = 1;
                        }
                    }
                }
            }
            average = neighbor / count;
            if(average <= t)
            {
                answer++;
            }
        }
    }
    printf("%d", answer);
    return 0;
}