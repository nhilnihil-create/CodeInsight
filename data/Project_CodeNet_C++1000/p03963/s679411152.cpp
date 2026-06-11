#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll MOD = 1000000007;

int main() {
    int N, K; cin >> N >> K;
    ll ans = K;
    rep(i,N-1) ans *= K-1;
  
    cout << ans << endl;
    
    return 0;
}
