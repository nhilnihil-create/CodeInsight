#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a * b >= c * d)
        cout << a * b << endl;
    else
        cout << c * d << endl;
}

int main()
{
    solve();
    return 0;
}