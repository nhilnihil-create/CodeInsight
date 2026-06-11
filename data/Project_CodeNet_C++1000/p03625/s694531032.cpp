#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(all(A));
    vector<ll> use;
    vector<ll> tmp;
    rep(i, N) {
        if (tmp.empty() || tmp.back() != A[i]) {
            tmp.push_back(A[i]);
        } else {
            tmp.pop_back();
            use.push_back(A[i]);
        }
    }
    sort(all(use));
    ll ans = 0;
    if (use.size() >= 2) {
        ll a = use[use.size()-1];
        ll b = use[use.size()-2];
        ans = a * b;
    }
    cout << ans << endl;
}