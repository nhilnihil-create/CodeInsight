#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    ll Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;
    S = min({S, H*2, Q*4});
    ll ans = S* N;
    ans = min(ans, N/2 * D + (N%2)*S);
    cout << ans << endl;
    return 0;
}

