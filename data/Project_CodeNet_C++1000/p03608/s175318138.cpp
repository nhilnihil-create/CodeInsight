#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
const int64_t INF = 1LL << 60;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    int64_t N, M, R;
    cin >> N >> M >> R;
    vector<int64_t> r(R), A(M), B(M), C(M);
    rep(i, 0, R) cin >> r.at(i);
    sort(all(r));
    rep(i, 0, M) cin >> A.at(i) >> B.at(i) >> C.at(i);
    vector<vector<int64_t>> d(N, vector<int64_t>(N, INF));
    rep(i, 0, N){
        d.at(i).at(i) = 0;
    }
    rep(i, 0, M){
        d.at(A.at(i) - 1).at(B.at(i) - 1) = C.at(i);
        d.at(B.at(i) - 1).at(A.at(i) - 1) = C.at(i);
    }
    rep(k, 0, N){
        rep(i, 0, N){
            rep(j, 0, N){
                d.at(i).at(j) = min(d.at(i).at(j), + d.at(i).at(k) + d.at(k).at(j));
            }
        }
    }
    int64_t ans_f = INF;
    do{
        int64_t ans = 0;
        rep(i, 0, R - 1){
            ans += d.at(r.at(i + 1) - 1).at(r.at(i) - 1);
        }
        ans_f = min(ans_f, ans);
    }
    while(next_permutation(all(r)));
    
    cout << ans_f << endl;
}