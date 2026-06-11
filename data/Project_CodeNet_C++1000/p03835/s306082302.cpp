#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int K,S;
    long long ans=0;
    
    scanf("%d%d",&K,&S);
    
    for(int i=0;i<=K;i++)
    {
        for(int j=0;j<=K;j++)
        {
            if(i+j<=S && S-(i+j)<=K)
                ans++;
        }
    }
    
    printf("%lld",ans);
    
    return 0;
}