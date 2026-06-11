#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    string a, b, c;
    cin >> a >> b >> c;
    int asize = a.size();
    int bsize = b.size();
    if (a[asize - 1] == b[0] && b[bsize - 1] == c[0])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    solve();
    return 0;
}