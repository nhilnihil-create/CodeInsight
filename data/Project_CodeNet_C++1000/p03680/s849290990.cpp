#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, n) cin >> a[i + 1];
    int next = a[1];
    int ans = 0;
    rep(i, n)
    {
        ans++;
        if (next == 2)
        {
            cout << ans << endl;
            return 0;
        }
        next = a[next];
    }
    cout << "-1" << endl;
    return 0;
}