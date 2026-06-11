#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<50;
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rnr(i,a,b) for(int i=int(a);i>=int(b);i--)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N, M, R; cin >> N >> M >> R;
    //R is very tiny
    int r[R];
    rep(i, R) cin >> r[i], --r[i];
    int A[M], B[M], C[M];
    vector<vector<ll>>G(N, vector<ll>(N, LLINF));
    rep(i, M) {
        cin >> A[i] >> B[i] >> C[i];
        G[--A[i]][--B[i]] = C[i];
        G[B[i]][A[i]] = C[i];
    }
    rep(i, N)
        G[i][i] = 0;
    for(int k = 0; k < N; ++k) {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    ll ans = LLINF;
    sort(r, r + R);
    do{
        ll sum = 0;
        int prev = r[0];
        for(int v : r) {
            sum += G[v][prev];
            prev = v;
        }
        ans = min(ans, sum);
    }while(next_permutation(r, r + R));

    cout << ans << endl;
}
