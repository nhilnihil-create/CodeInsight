#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c; cin >> a >> b >> c;
    if (a == b && b == c) cout << 1 << endl;
    else if (a == b || b == c || c == a) cout << 2 << endl;
    else cout << 3 << endl;
    return 0;
}
