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
        long long s,c,ans=0;
        
        scanf("%lld%lld",&s,&c);
        
        ans=min(s,c/2);
        
        c-=(ans*2);
        
        s-=ans;
        
        ans+=c/4;
        
        long long rem=c%4;
        
        ans+=min(s,rem/2);
        
        printf("%lld",ans);
    }

    return 0;
}