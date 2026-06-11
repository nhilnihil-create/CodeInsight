#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int t;
    
    // scanf("%d",&t);
    
    t=1;
    
    while(t--)
    {
        int n;
        
        scanf("%d",&n);
        
        long long mod=1e9+7,ans=1;
        
        for(int i=1;i<=n;i++)
            ans=(ans*i)%mod;
        
        printf("%lld",ans);
    }

    return 0;
}