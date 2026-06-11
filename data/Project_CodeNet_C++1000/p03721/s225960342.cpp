#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

vector<P> vp;

int main(){
    ll n, k;
    cin >> n >> k;
    rep(i, n){
        ll a, b;
        cin >> a >> b;
        vp.push_back({a,b});
    }
    sort(vp.begin(), vp.end());

    ll cnt = 0;

    rep(i, n){
        cnt += vp[i].second;
        if (cnt >= k){
            cout << vp[i].first << endl;
            break;
        }
    }

    return 0;
}
