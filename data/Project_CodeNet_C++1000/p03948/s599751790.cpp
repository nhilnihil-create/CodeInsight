#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<int> min_a(n), max_a(n);
    min_a[0] = a[0];
    max_a[n-1] = a[n-1];
    rep(i, 1, n) min_a[i] = min(min_a[i - 1], a[i]);
    rrep(i, n - 1, 0) max_a[i] = max(max_a[i + 1], a[i]);

    int max_diff = 0;
    rep(i, 0, n - 1)
        max_diff = max(max_diff, max_a[i + 1] - min_a[i]);
    
    map<int, int> small_cnt, big_cnt;
    rep(i, 0, n - 1)
    if (max_a[i + 1] - a[i] == max_diff)
        ++small_cnt[a[i]];
    rrep(i, n, 1)
    if (a[i] - min_a[i - 1] == max_diff)
        ++big_cnt[a[i]];

    ll ans = 0;
    for (auto s_cnt: small_cnt)
    {
        int small, cnt;
        tie(small, cnt) = s_cnt;
        ans += min(cnt, big_cnt[max_diff + small]);
        // cout << small << ' ' << cnt << ' ' << max_diff - small << ' ' << big_cnt[max_diff - small] << endl;
    }
    cout << ans << endl;
    return 0;
}