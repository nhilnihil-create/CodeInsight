#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x, t; cin >> x >> t;
    cout << max(0, x - t) << endl;
    return 0;
}