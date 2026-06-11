#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int main()
{
    long long a,b,c;
    long long maxn;
    scanf("%lld %lld %lld",&a,&b,&c);
    if(a>b)maxn=a;
    else maxn=b;
    if(maxn>c)maxn=maxn;
    else maxn=c;
    if(maxn%2==0)printf("0");
    else
    {
        if(maxn==a)printf("%lld",b*c);
        else if(maxn==b)printf("%lld",a*c);
        else if(maxn==c)printf("%lld",a*b);
    }

}