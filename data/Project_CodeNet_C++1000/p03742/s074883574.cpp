#include <iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
//#define for1(i,a) for(i=0;i<a;i++)
//#define for2(i,a) for(i=1;i<=a;i++)
using namespace std;
ll n,m;
int main()
{
    scanf("%lld%lld",&n,&m);
    if(n<m)
    {
        ll t=n;
        n=m;
        m=t;
    }
    if(m<=n-2) printf("Alice\n");
    else printf("Brown\n");
    return 0;
}
