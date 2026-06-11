#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x, a, b; cin >> x >> a >> b;
    if (b - a <= 0) cout << "delicious" << endl;
    else if (b - a <= x) cout << "safe" << endl;
    else cout << "dangerous" << endl;
    return 0;
}
