#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    int INF = 1001001001;
    vector<vector<int>> d(n, vector<int>(n, INF));
    vector<P> p;
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        d[a][b] = c;
        d[b][a] = c;
        p.push_back(make_pair(a, b));
    }
    rep(i, n)d[i][i] = 0;
    vector<vector<int>> dd = d;
    rep(k, n)rep(i, n)rep(j, n){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }

    int ans = 0;
    rep(i, m){
        bool valid = false;
        int l = p[i].first;
        int r = p[i].second;
        rep(j, n)rep(k, n){
            if(valid)break;
            if(j == k)continue;
            if(d[j][k] == d[j][l] + dd[l][r] + d[r][k])valid = true;
        }
        if(!valid)ans++;
    }
    cout << ans << endl;
}