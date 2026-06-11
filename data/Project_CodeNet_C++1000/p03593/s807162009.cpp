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
    ll H, W;
    cin >> H >> W;
    vector<string> A(H);
    REP(i,0,H) cin >> A[i];

    vec C(26, 0);
    REP(i,0,H) {
        REP(j,0,W) ++C[A[i][j]-'a'];
    }

    bool f = true;
    if(H % 2 == 0 && W % 2 == 0) {
        REP(i,0,26) {
            if(C[i] % 4 != 0) f = false;
        }
    }
    else if(H % 2 == 0 && W % 2 == 1) {
        ll cnt = H * (W - 1);
        REP(i,0,26) {
            while(C[i] >= 4 && cnt > 0) {
                C[i] -= 4;
                cnt -= 4;
            }
        }
        if(cnt > 0) f = false;
        REP(i,0,26) {
            if(C[i] % 2 != 0) f = false;
        }
    }
    else if(H % 2 == 1 && W % 2 == 0) {
        ll cnt = (H - 1) * W;
        REP(i,0,26) {
            while(C[i] >= 4 && cnt > 0) {
                C[i] -= 4;
                cnt -= 4;;
            }
        }
        if(cnt > 0) f = false;
        REP(i,0,26) {
            if(C[i] % 2 != 0) f = false;
        }
    }
    else {
        ll cnt = (H - 1) * (W - 1);
        REP(i,0,26) {
            while(C[i] >= 4 && cnt > 0) {
                C[i] -= 4;
                cnt -= 4;
            }
        }
        if(cnt > 0) f = false;
        cnt = H + W - 2;
        REP(i,0,26) {
            while(C[i] >= 2 && cnt > 0) {
                C[i] -= 2;
                cnt -= 2;
            }
        }
        if(cnt > 0) f = false;
        cnt = 0;
        REP(i,0,26) cnt += C[i];
        if(cnt != 1) f = false;
    }

    if(f) PR("Yes");
    else PR("No");

    return 0;
}

/*



*/