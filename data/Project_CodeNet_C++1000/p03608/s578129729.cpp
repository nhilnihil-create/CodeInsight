#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const int inf = int(1e19);
const int mod = int(1e9) + 7;
const int n_max = 200;
ll d[n_max][n_max];

void floyd_warshall(int n){
    rep(k, n)
        rep(i, n)
            rep(j, n) d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
}

int main(){
    int n, m, r; cin >> n >> m >> r;
    vector<int> R(r);
    rep(i, r) cin >> R[i];
    rep(i, n_max){
        rep(j, n_max){
            if(i == j) d[i][j] = 0;
            else d[i][j] = inf;
        }
    }

    rep(i, m){
        int a, b, c; cin >> a >> b >> c;
        d[a - 1][b - 1] = c;
        d[b - 1][a - 1] = c;
    }

    floyd_warshall(n);
    sort(all(R));
    ll res = inf;
    do{
        ll temp = 0;
        rep(i, r - 1){
            temp += d[R[i] - 1][R[i + 1] - 1];
        }
        res = min(res, temp);
    }
    while(next_permutation(all(R)));
    cout << res << endl;

}