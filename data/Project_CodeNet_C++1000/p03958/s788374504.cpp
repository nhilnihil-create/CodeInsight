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
    int K,T; cin >> K >> T;
    vi A(T); rep(i,T) cin >> A[i];
    sort(A.begin(), A.end());
    int ans = 0;
    if(T == 1) ans = K-1;
    else {
        ans = 2*A[T-1] - K - 1;
        if(ans < 0) ans = 0;
    }

    cout << ans;
    return 0;
}
