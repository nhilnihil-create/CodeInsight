#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long K;
    scanf("%lld",&K);
    long long arr[50];
    for(int i=0;i<50;i++)
    {
        arr[i] = i + (K/50);
    }
    for(int i=0;i<(K%50);i++)
    {
        arr[i] += (long long)50;
        for(int j = 0;j<50;j++)
        {   if(j == i)
                continue;
            else
                arr[j]--;
        }
    }

    printf("50\n");
    for(int i=0;i<50;i++)
        printf("%lld ",arr[i]);

}
