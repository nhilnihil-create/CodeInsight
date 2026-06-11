/**
*    author:  yuya1234
*    created: 26.06.2020 13:06:46
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))
int digit(int n)
{
    int d=0;
    while(n>0)
    {
        n/=10;
        d++;
    }
    return d;
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n;
    cin>>n;
    ll ans=100000000000;

    for(ll i=1;i<=sqrt(n);i++)
    {
        if(i*(ll)(n/i)==n)
        {
            ans = min(ans,max((ll)i,(ll)(n/i)));
        }
    }

    cout<<digit(ans)<<endl;

    return 0;
}