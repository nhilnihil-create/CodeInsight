#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (int i = 0; i < (n); i++)
#define IREP(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, k, n) for (int i = (k); i < (n); i++)
#define REPEACH(itr, k) for (auto &&itr : k)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;


const ll INF = 1ll << 60;
const ll MOD = 1000000007;

int main()
{
    ll n,a,b;
    cin >> n >> a >> b;
    ll ans=0;
    ll now;
    cin >> now;
    REP(i,n-1){
        ll x;
        cin >> x;
        ans+=min((x-now)*a,b);
        now=x;
    }
    cout << ans << endl;
}