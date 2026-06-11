/**
*    author:  yuya1234
*    created: 25.06.2020 14:12:14
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

    int n,m;
    cin>>n>>m;

    int a[50],tmp1,tmp2;
    MEMSET(a,0);
    REP(i,m)
    {
        cin>>tmp1>>tmp2;
        a[tmp1-1]++;
        a[tmp2-1]++;
    }

    REP(i,n)cout<<a[i]<<endl;

    return 0;
}