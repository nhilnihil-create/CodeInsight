#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a == 1)
        a = 14;
    if (b == 1)
        b = 14;
    if (a > b)
        cout << "Alice" << endl;
    else if (a < b)
        cout << "Bob" << endl;
    else
        cout << "Draw" << endl;
}

int main()
{
    solve();
    return 0;
}