#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll n,x=0,y,i;
    ll a[200010];

    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);

    sort(a+1,a+1+n,greater<int>());

    for(;x<=a[x];x++);
    x--;

    if((a[x]-x)%2==0)
    {
        y=0;
        for(;x<=a[x+y];y++);
        if(y%2)
        {
            printf("Second\n");
            return 0;
        }
    }
    printf("First\n");
    return 0;
}
