#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    ll tnow, anow; cin >> tnow >> anow;
    rep(i, N-1){
        ll t, a; cin >> t >> a;
        ll x = ((tnow-1) / t) + 1;
        ll y = ((anow-1) / a) + 1;
        ll z = max(x, y);
        tnow = t*z;
        anow = a*z;
    }

    cout << tnow + anow << endl;

    return 0;
}