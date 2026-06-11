/**
*    author:  yuya1234
*    created: 26.06.2020 16:07:37
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

    int n;
    ll a[100010];

    cin>>n;
    REP(i,n)cin>>a[i];

    ll cnt=1;
    int status=0,tmp=a[0];

    REP(i,n)
    {
        if(status==0)
        {
            if(tmp<a[i])status=1;
            else if(tmp>a[i])status=-1;
        }
        else if(status==1)
        {
            if(tmp>a[i])
            {
                status=0;
                cnt++;
            }
        }
        else
        {
            if(tmp<a[i])
            {
                status=0;
                cnt++;
            }
        }
            tmp=a[i];
    }

    cout<<cnt<<endl;

    return 0;
}