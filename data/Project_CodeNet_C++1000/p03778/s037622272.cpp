#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int W, a, b;
    cin >> W >> a >> b;
    if(abs(a-b)<=W) {
        cout << 0 << '\n';
        return 0;
    }
    vec<int> r(4);
    r[0] = a;
    r[1] = b;
    r[2] = a+W;
    r[3] = b+W;
    sort(all(r));
    cout << r[2]-r[1] << '\n';
}
