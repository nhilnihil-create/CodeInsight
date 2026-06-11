#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    
    int ans = 0;
    rep(i, N) {
        int l,r;
        cin >> l >> r;
        ans+=(r-l+1);
    }
    cout << ans << endl;
}
