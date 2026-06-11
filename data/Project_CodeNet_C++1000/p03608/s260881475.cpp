#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll INF = 1001001001001;

int main() {
    int N, M, R; cin >> N >> M >> R;
    vector<int> r(R);
    rep(i, R){
        cin >> r[i];
        r[i]--;
    }
    sort(r.begin(), r.end());

    ll d[N][N];
    rep(i, N){
        rep(j, N){
            if(i == j){
                d[i][j] = 0;
            } else {
                d[i][j] = INF;
            }
        }
    }

    rep(i, M){
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        d[a][b] = c;
        d[b][a] = c;
    }

    rep(k, N){
        rep(i, N){
            rep(j, N){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int last = INF;
    do {
        int ans = 0;
        rep(i, R-1){
            ans += d[r[i]][r[i+1]];
        }
        last = min(last, ans);
    } while(next_permutation(r.begin(), r.end()));
    
    cout << last << endl;

    return 0;
}