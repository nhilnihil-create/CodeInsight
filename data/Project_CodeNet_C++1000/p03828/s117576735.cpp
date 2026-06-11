#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

int primes[1001];

void facts(int n)
{
    int root=sqrt(n);
    
    for(int i=2;i<=root;i++)
    {
        while(n%i==0)
        {
            primes[i]++;
            n/=i;
        }
    }
    
    if(n!=1)
        primes[n]++;
}

int main()
{
    int n,mod=1e9+7;
    long long ans=1;
    
    scanf("%d",&n);
    
    for(int i=2;i<=n;i++)
        facts(i);
    
    for(int i=2;i<=n;i++)
        ans=(ans*(primes[i]+1))%mod;
    
    printf("%lld",ans);

    return 0;
}