#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

int main()
{
    ll N, P;
    cin >> N >> P;
    vec C(2, 0);
    REP(i,0,N) {
        ll a;
        cin >> a;
        ++C[a%2];
    }

    ll ans;
    ll K = C[1];
    if(K == 0) {
        if(P == 0) {
            ans = 1;
            REP(i,0,N) ans *= 2;
        }
        else ans = 0;
    }
    else {
        mat nCr(K+1, vec(K+1, 0));
        nCr[0][0] = 1;
        nCr[1][0] = 1;
        nCr[1][1] = 1;
        REP(i,2,K+1) {
            nCr[i][0] = 1;
            REP(j,1,K+1) nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
        }
        ans = 0;
        if(P == 0) {
            REP(i,0,K/2+1) ans += nCr[K][i*2]; 
        }
        else {
            REP(i,1,(K+1)/2+1) ans += nCr[K][i*2-1]; 
        }
        REP(i,0,N-K) ans *= 2;
    }
    PR(ans);

    return 0;
}

/*



*/