#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<pair<int, int>> a;
    rep(i, N) {
        int s; cin >> s;
        a.push_back({s, -(i + 1)});
    }
    a.push_back({0, 0});
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    /*
    rep(i, N) {
        cout << a[i].first << " " << -a[i].second << endl;
    }
    */
    int ans[100010] = {};
    pair<int, int> focus;
    rep(i, N) {
        if (i == 0 || a[i].first > focus.first || -a[i].second < -focus.second) 
            focus = a[i];
        //cout << a[i].first << " " << -a[i].second << " " << -focus.second << " " << i + 1 <<  endl;
        ans[-focus.second] += (a[i].first - a[i + 1].first) * (i + 1);
    }
    REP(i, 1, N) {
        cout << ans[i] << endl;
    }

    return 0;
}
