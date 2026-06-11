#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll x, y; cin >> x >> y;
    cout << (abs(x - y) > 1 ? "Alice" : "Brown") << endl;
    return 0;
}
