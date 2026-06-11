#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, __VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

#define MOD 1000000007
#define INF 1000000000
#define MAX_N 100010

ll W, H;
vector<ll> P, Q;

int main()
{
    ll ans = 0;
    ll edge = 0;
    cin >> W >> H;
    REP(i, W) {
        ll tmp;
        cin >> tmp;
        P.push_back(tmp);
        ans += tmp;
        edge++;
    }
    REP(i, H) {
        ll tmp;
        cin >> tmp;
        Q.push_back(tmp);
        ans += tmp;
        edge++;
    }
    //printf("ans: %lld\n", ans);
    //printf("edge: %lld\n", edge);
    SORT(P);
    SORT(Q);
    ll p_ind = 0, q_ind = 0;
    while(edge < (W+1) * (H+1) - 1) {
        if(P[p_ind] < Q[q_ind]) {
            ans += (H - q_ind) * P[p_ind];
            //printf("P[%lld]: %lld\n", p_ind, P[p_ind]);
            p_ind++;
            edge += (H - q_ind >= 0) ? (H - q_ind) : 0;
        } else {
            ans += (W - p_ind) * Q[q_ind];
            //printf("Q[%lld]: %lld\n", q_ind, Q[q_ind]);
            q_ind++;
            edge += (W - p_ind >= 0) ? (W - p_ind) : 0;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
