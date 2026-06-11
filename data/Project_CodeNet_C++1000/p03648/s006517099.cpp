#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define PI acos(-1.0)

typedef long long ll;
const int maxn=1e5+5;

int main()
{
    ll k;
    scanf("%lld",&k);
    int n=50;
    cout << n << endl;
    ll res=k%50;
    ll x=k/50-1;
    ll cnt=res;
    for(ll i=1;i<=50;i++)
    {
        if(cnt>0)
        {
            printf("%lld ",i+50-res+1+x );
            cnt--;
        }
        else
            printf("%lld ",i-res+x);
    }
    cout << endl;
    return 0;
}
