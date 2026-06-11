#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int x, a, b;
    cin >> x >> a >> b;
    if (-a + b <= 0)
        cout << "delicious" << endl;
    else if (-a + b <= x)
        cout << "safe" << endl;
    else
        cout << "dangerous" << endl;
}

int main()
{
    solve();
    return 0;
}