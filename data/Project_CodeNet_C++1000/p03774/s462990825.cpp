#include <bits/stdc++.h>
#define rep(i, a, n) for(ll i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    rep(i, 0, n) cin >> a[i] >> b[i];
    rep(i, 0, m) cin >> c[i] >> d[i];
    vector<int> ans(n);
    rep(i, 0, n){
        int mn = INF;
        rep(j, 0, m){
            int dist = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if(dist < mn){
                mn = dist;
                ans[i] = j+1;
            }
        }
    }
    rep(i, 0, n) cout << ans[i] << endl;
    return 0;
}
