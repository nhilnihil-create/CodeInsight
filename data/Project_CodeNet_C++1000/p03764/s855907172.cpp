/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx=1e5+5;
const int MOD=1e9+7;
ll ara[mx];
int main ()
{
    ll n,m;
    scanf ("%lld %lld",&n,&m);
    ll sum1=0;
    for (int i=0;i<n;i++) {
        scanf ("%lld",&ara[i]);
        if (i) {
            ll x=ara[i]-ara[i-1];
            sum1+=x*i*(n-i);
            sum1%=MOD;
        }
    }
    ll sum2=0;
    for (int i=0;i<m;i++) {
        scanf ("%lld",&ara[i]);
        if (i) {
            ll x=ara[i]-ara[i-1];
            sum2+=x*i*(m-i);
            sum2%=MOD;
        }
    }
    ll ans=(sum1*sum2)%MOD;
    printf ("%lld\n",ans);

    return 0;
}
