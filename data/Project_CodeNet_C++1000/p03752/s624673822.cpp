#include <bits/stdc++.h>
#include <numeric>
#define ll long long
#define int ll

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define irep(itr, st) for(auto itr = (st).begin(); itr != (st).end(); ++itr)
#define irrep(itr, st) for(auto itr = (st).rbegin(); itr != (st).rend(); ++itr)

#define pb emplace_back
#define mp make_pair

using namespace std;

const ll MOD = 998244353;
const ll INF = (ll)1000000007 * 1000000007;

#ifdef DEBUG
#define PRINT(A) std::cout << (#A) << ":" << (A) << std::endl;
#else
#define PRINT(A)
#endif

typedef pair<ll, ll> P;

template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll R, C, N, K;

bool v[15][10005];

ll a[20];

signed main() {

    cin >> N >> K;


    rep(i,N){
        cin >> a[i];
    }

    int minCost = INF;
    rep(i, 1ll << N){
        ll newA[15];
        rep(j,N) newA[j] = a[j];
        int count = 0;
        rep(j, N){
            if(i >> j & 1){
                count ++;
            }
        }
        if(count == K){
            rep(j,N){
                if(i >> j & 1){
                    rep(k,j){
                        chmax(newA[j], newA[k]+1);
                    }
                }
            }
            
            int cost = 0;
            rep(j,N){
                PRINT(newA[j])
                cost += (newA[j] - a[j]);
            }
            PRINT(cost)
            chmin(minCost, cost);
        }
    }

    cout << minCost << endl;
}
