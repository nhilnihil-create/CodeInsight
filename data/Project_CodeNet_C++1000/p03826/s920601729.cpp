#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << max(a * b, c * d) << endl;
    return 0;
}
