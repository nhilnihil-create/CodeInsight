#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main()
{
    long long x;
    
    scanf("%lld",&x);
    
    long long ans=(x/11)*2;
    
    if(x%11!=0)
    {
        if(x%11<=6)
            ans++;
        else
            ans+=2;
    }
    
    printf("%lld",ans);

    return 0;
}