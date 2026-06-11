#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using ll = long long;
using P = pair<int, int>;

int main()
{
    int k, t;
    cin >> k >> t;
    vector<int> a(t);
    rep(i, t) cin >> a[i];
    int sum = 0;
    rep(i, t) sum += a[i];
    int mx = *max_element(all(a));
    int b = sum - mx;
    int ans = max(mx - 1 - b, 0);
    cout << ans << endl;
    return 0;
}