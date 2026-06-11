#include<bits/stdc++.h>
using namespace std;

int N;
int A[100010];
int a,b;

char S[2][100010] = {"First","Second"};

int gdc(int a,int b)
{
    if(b == 0)return a;
    return gdc(b,a % b);
}

int main()
{
    int cnt = 0;
    scanf("%d",&N);
    for(int i = 0; i < N; i++)scanf("%d",&A[i]);

    int k = 1;
    while(1)
    {
        k = 1 - k;
        cnt = 0;
        for(int i = 0; i < N; i++)if(A[i] % 2 == 0)cnt++;
        if(cnt % 2){printf("%s\n",S[k]);return 0;}
        cnt = N - cnt;
        if(cnt > 1){printf("%s\n",S[1 - k]);return 0;}
        for(int i = 0; i < N; i++)if(A[i] == 1){printf("%s\n",S[1 - k]);return 0;}
        for(int i = 0; i < N; i++)if(A[i] % 2)A[i]--;
        int GDC = A[0];
        for(int i = 1; i < N; i++)GDC = gdc(GDC,A[i]);
        for(int i = 0; i < N; i++)A[i] /= GDC;
    }
    return 0;
}
