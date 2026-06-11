#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll a,b,sum,diff;
    char c = 'a';

    diff=a-b;
    //cin >> a >> c >> b ;
    scanf("%lld %c %lld",&a,&c,&b);
    sum = a+b;
    diff=a-b;
    if(c =='+')
    {
        printf("%lld\n",sum);
    }
    else
        printf("%lld\n",diff);
}
