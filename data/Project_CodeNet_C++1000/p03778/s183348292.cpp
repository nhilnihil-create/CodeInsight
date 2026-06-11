#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int w, a, b;
    cin >> w >> a >> b;
    if (a > b)
        swap(a, b);
    cout << max(b - (a + w), 0) << endl;
}

int main()
{
    solve();
    return 0;
}