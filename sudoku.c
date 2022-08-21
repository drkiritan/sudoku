#include <stdio.h>
#define N 9
#define B 3

void Display(int table[N][N])
{
    int i,j;
    puts("Answer");
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%d", table[i][j]);
        }
        putchar('\n');
    }
}

int checkNum(int i,int j,int n,int t[N][N])
{
    int x,y,tx,ty;
    tx = j / B * B;
    ty = i / B * B;

    for(x = 0; x < N; x++)
    {
        if(t[i][x] == n)
        {
            return 0;
        }
    }
    for(y = 0; y < N; y++)
    {
        if(t[y][j] == n)
        {
            return 0;
        }
    }
    for(y = 0; y < B; y++)
    {
        for(x = 0; x < B; x++)
        {
            if(t[ty+y][tx+x] == n)
            {
                return 0;
            }
        }
    }
    return 1;
}

int putNum(int i,int j,int n,int t[N][N])
{
    int flag = 0;
    if(t[i][j] != n)
    {
        if(t[i][j] != 0)
        {
            return 0;
        }
        if(checkNum(i,j,n,t) == 0)
        {
            return 0;
        }
        t[i][j] = n;
    }
    else
    {
        flag = 1;
    }


    if(i == N-1 && j == N-1)
    {
        Display(t);
    }
    else
    {
        int m,box;
        int next_i,next_j;

        if(j+1 >= N)
        {
            next_i = i+1;
            next_j = 0;
        }
        else
        {
            next_i = i;
            next_j = j+1;
        }
        for(m = 1; m <= N; m++)
        {
            box = putNum(next_i,next_j,m,t);
        }
    }

    if(flag == 0)
    {
        t[i][j] = 0;
    }
}

void Sudoku(int table[N][N])
{
    int i,box;
    for(i = 1; i <= N; i++)
    {
        box = putNum(0,0,i,table);
    }
}

int main(void)
{
    int i,j,num;
    int table[N][N];
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            scanf("%d", &table[i][j]);
        }
    }
    Sudoku(table);
    return 0;
}