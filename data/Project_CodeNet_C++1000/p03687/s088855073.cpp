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
vector<int> v[26];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin >> S;
    int n = S.length();
    rep(i, 26) v[i].push_back(-1);
    rep(i, n) {
        v[S[i] - 'a'].push_back(i);
    }
    rep(i, 26) v[i].push_back(n);
    int ans = n;
    rep(i, 26) {
        int tmp = 0;
        rep(j, (int)v[i].size() - 1) {
            tmp = max(tmp, v[i][j + 1] - v[i][j]);
        }
        ans = min(ans, tmp);
    }
    cout << ans - 1 << endl;

    return 0;
}
// 10203456789