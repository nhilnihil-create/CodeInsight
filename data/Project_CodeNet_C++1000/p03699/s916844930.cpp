#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;

    vec<int> s(N);
    bool isAll10x = true;
    int ans       = 0;
    rep(i, N) {
        cin >> s[i];
        if (s[i] % 10 != 0) isAll10x = false;
        ans += s[i];
    }
    if (isAll10x) {
        cout << 0 << endl;
        return 0;
    }
    if(ans%10!=0) {
        cout << ans << endl;
        return 0;
    }
    sort(all(s));
    for (auto e : s) {
        if (e % 10 != 0) {
            cout << ans - e << endl;
            return 0;
        }
    }
}
