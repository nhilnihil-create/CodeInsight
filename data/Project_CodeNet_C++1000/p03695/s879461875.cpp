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
    ll N;
    cin >> N;
    vec A(N);
    REP(i,0,N) cin >> A[i];

    vec C(8, 0);
    ll cnt1 = 0, cnt2 = 0;
    REP(i,0,N) {
        if(A[i] < 3200) C[A[i]/400] = 1;
        else ++cnt2;
    }
    REP(i,0,8) cnt1 += C[i];
    PS(MAX(1,cnt1));
    PR(cnt1+cnt2);

    return 0;
}

/*



*/