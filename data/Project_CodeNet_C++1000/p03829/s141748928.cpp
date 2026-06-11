#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    ll A, B; cin >> A >> B;
    vector<ll> X(N);
    rep(i, N){
        cin >> X[i];
    }

    ll ans = 0;
    for (int i = 1; i < N; i++){
        ll d = X[i] - X[i-1];
        d *= A;
        if(d > B){
            ans += B;
        } else {
            ans += d;
        }
    }

    cout << ans << endl;

    return 0;
}