#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string a, b, c; cin >> a >> b >> c;
    if (a.back() == b.front() && b.back() == c.front()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
