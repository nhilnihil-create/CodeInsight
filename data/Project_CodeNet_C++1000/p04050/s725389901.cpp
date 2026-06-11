#include<bits/stdc++.h>
using namespace std;

int N,M,A[100010];

int main()
{
    scanf("%d%d",&N,&M);
    for(int i = 0; i < M; i++)scanf("%d",A + i);
    int cnt = 0;
    for(int i = 0; i < M; i++)if(A[i] % 2)cnt++;
    if(cnt > 2)
    {
        printf("Impossible\n");
        return 0;
    }
    if(N == 1)
    {
        printf("1\n");
        printf("1\n");
        printf("1\n");
    }
    else if(M == 1)
    {
        printf("%d\n",A[0]);
        printf("2\n");
        printf("%d %d\n",A[0] - 1,1);
    }
    else if(M == 2)
    {
        printf("%d %d\n",A[0],A[1]);
        printf("%d\n",2 - (A[0] == 1));
        if(A[0] != 1)printf("%d ",A[0] - 1);
        printf("%d\n",A[1] + 1);
    }
    else
    {
        bool F = true;
        for(int i = 0; i < M; i++)
        {
            if(A[i] % 2)
            {
                if(F)
                {
                    swap(A[i],A[0]);
                    F = false;
                }
                else swap(A[i],A[M - 1]);
            }
        }
        for(int i = 0; i < M; i++)
        {
            printf("%d",A[i]);
            if(i != M - 1)printf(" ");
        }
        printf("\n");
        printf("%d\n",M - (A[0] == 1));
        if(A[0] != 1)printf("%d ",A[0] - 1);
        for(int i = 1; i < M - 1; i++)
            printf("%d ",A[i]);
        printf("%d\n",A[M - 1] + 1);
    }
    return 0;
}
