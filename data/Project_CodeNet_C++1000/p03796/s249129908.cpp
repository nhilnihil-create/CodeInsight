/**
*    author:  yuya1234
*    created: 24.06.2020 15:15:47
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n, ans=1;
    cin>>n;

    REP(i,n)
    {
        ans*=i+1;
        ans%=1000000000+7;
    }

    cout << ans << endl;
    return 0;
}