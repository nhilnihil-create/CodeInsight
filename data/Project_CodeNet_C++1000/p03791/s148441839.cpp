#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
long long a[100011];
long long MOD=1000000007;

int main()
{
    int i,j,k;
    int xx;
    
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    long long r=0;
    long long ans=1;
    for(i=1;i<=n;i++)
    {
        r++;
        if(r*2-1>a[i])
        {
            ans=ans*r%MOD;
            r--;
        }
    }
    while(r!=0)
    {
        ans=ans*r%MOD;
        r--;
    }
    
    cout<<ans<<endl;
    
    
    return 0;
}

