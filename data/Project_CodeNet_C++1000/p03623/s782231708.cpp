#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int x, a, b;
    cin >> x >> a >> b;
    int A = abs(x - a);
    int B = abs(x - b);
    if (A < B)
        cout << "A" << endl;
    else
        cout << "B" << endl;
}

int main()
{
    solve();
    return 0;
}