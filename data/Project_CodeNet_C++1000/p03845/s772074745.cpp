#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> t(n);
    rep(i, n) cin >> t[i];
    int m;
    cin >> m;
    rep(i, m)
    {
        int p, x;
        cin >> p >> x;
        p--;
        int sum = 0;
        int tmp = t[p];
        t[p] = x;
        rep(j, n) sum += t[j];
        cout << sum << endl;
        t[p] = tmp;
    }
}

int main()
{
    solve();
    return 0;
}