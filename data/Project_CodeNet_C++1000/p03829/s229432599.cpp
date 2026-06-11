#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,i,a,b,m,c,sum=0,x,d;
    scanf("%lld%lld%lld",&n,&a,&b);
    c=ceil(b*1.0/a);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&m);
        if(i==0) x=0;
        else x=m-d;
        if(x>=c) sum+=b;
        else sum+=x*a;
        d=m;
    }
    printf("%lld",sum);
    return 0;
}