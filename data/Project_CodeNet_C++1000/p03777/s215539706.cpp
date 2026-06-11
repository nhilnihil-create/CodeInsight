#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    char a, b;
    cin >> a >> b;
    if (a == 'H' && b == 'H')
        cout << "H" << endl;
    else if (a == 'D' && b == 'D')
        cout << "H" << endl;
    else
        cout << "D" << endl;
}

int main()
{
    solve();
    return 0;
}