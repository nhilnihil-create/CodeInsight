#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b == c || a + c == b || b + c == a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    solve();
    return 0;
}