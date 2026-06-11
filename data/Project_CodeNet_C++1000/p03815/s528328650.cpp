#include<stdio.h>
#include<string.h>
using namespace std;
#define ll long long int
int main()
{
    ll a;
    while(~scanf("%lld",&a))
    {
        ll mod=11;
        ll output=a/mod*2;
        a%=mod;
        if(a>=1&&a<=6)output++;
        if(a>=7&&a<=10)output+=2;
        printf("%lld\n",output);
    }
}