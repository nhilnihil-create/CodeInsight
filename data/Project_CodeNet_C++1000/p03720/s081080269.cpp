/**
*    created: 21.06.2020 01:18:00
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(a) (a).begin(),(a).end()
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> r(n);
    int a, b;
    rep(i,m) {
        cin >> a >> b;
        r[a-1]++;
        r[b-1]++;
    }
    rep(i,n) cout << r[i] << endl;
    return 0;
}