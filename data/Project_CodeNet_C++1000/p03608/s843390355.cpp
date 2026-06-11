#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll n, M, R;
    cin >> n >> M >> R;

    vector<ll> r(R);
    rep(i, R) cin >> r[i];
    vector<ll> A(M), B(M), C(M);
    rep(i, M) cin >> A[i] >> B[i] >> C[i];
    
    
    // Warshall–Floyd 
    ll INF = 1e18;
    vector<vector<ll> > d(n, vector<ll>(n, INF));
    rep(i, M) {
        d[A[i]-1][B[i]-1] = C[i];
        d[B[i]-1][A[i]-1] = C[i];
    }
    rep(k, n) {
        rep (i, n) {
            rep (j, n) {
                if (d[i][k] < INF && d[k][j] < INF) {
                    d[i][j] = min(
                        d[i][j], d[i][k] + d[k][j]);
                }
            }
        }        
    }

    
    auto nums = r;
    // 事前にソートしないと全部列挙できない
    sort(all(nums));
    ll res = INF;
    do {
        ll dist = 0;
        rep(i, nums.size() - 1) {
            dist += d[nums[i]-1][nums[i+1]-1];
            dist = min(dist, INF);
        }
        res = min(res, dist);
    } while (next_permutation(nums.begin(), nums.end()));

    put(res);
}
signed main(){ Main();return 0;}