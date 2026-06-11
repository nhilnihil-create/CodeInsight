#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,m;
inline long long gcd(long long x,long long y)
{
    if(y==0) return x;
    return gcd(y,x%y);
}
int main()
{
    scanf("%lld%lld",&n,&m);
    printf("%lld\n",3*(n-gcd(n,m)));
    return 0;
}
