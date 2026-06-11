#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;

    vec<int> a(N);
    rep(i, N) {
        cin >> a[i];
        --a[i];
    }
    int now = a[0];
    int count = 1;
    ++N;
    while(--N) {
        if(now == 1) {
            cout << count << endl;
            return 0;
        }
        now = a[now];
        ++count;
    }
    cout << -1 << endl;
}
