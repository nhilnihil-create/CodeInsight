#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll MOD = round(1e9+7);


int main() {
    ll N; cin >> N;
    vi A(N); rep(i,N) cin >> A[i];
    sort(A.begin(), A.end());

    ll sum = 0;
    rep(i,N) sum += A[i];
    ll ans = 1;
    rep(i,N-1){
        sum -= A[N-1-i];
        if(sum*2 < A[N-1-i]) break;
        ans++;
    }

    cout << ans;
    return 0;
}
