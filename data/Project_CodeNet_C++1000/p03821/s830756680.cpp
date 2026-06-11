#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ara[100005], b[100005];
int main()
{
    ll n;
    scanf("%lld", &n);
    for(int i=1; i<=n; i++)
    scanf("%lld %lld", &ara[i], &b[i]);
    ll res= 0;
    for(int i=n; i>=1; i--)
    if((res+ara[i])%b[i])
    res+= ((((res+ara[i])/b[i] + 1)*b[i])-(ara[i]+res));
    printf("%lld\n", res);
    return 0;
}
