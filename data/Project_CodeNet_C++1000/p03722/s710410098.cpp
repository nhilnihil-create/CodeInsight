#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, ll>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<P>> to(n);
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        to[a].push_back(make_pair(b, -c));
    }
    ll INF = 1001001001001001001;
    vector<ll> d(n, INF);
    d[0] = 0;
    ll ans = 0;
    rep(i, n){
        rep(v, n){
            for(P p : to[v]){
                int t = p.first;
                ll dist = p.second;
                if(d[v] != INF && d[t] > d[v] + dist){
                    d[t] = d[v] + dist;
                }
            }
        }
        if(i == n - 2)ans = d[n-1];
        else if(i == n - 1){
            if(ans != d[n-1])cout << "inf" << endl;
            else cout << -ans << endl;
        }
    }
}