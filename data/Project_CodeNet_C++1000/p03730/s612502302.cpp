/**
*    author:  yuya1234
*    created: 26.06.2020 16:26:38
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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll a,b,c;
    cin>>a>>b>>c;

    string ans="NO";
    for (ll i = 1; i < 100; i++)
    {
        if((i*a)%b==c)
        {
            ans="YES";
            break;
        }
    }
    
    cout<<ans<<endl;

    return 0;
}