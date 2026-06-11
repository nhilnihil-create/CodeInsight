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
    ll W, H, N;
    cin >> W >> H >> N;
    ll Xl = 0, Xu = W, Yl = 0, Yu = H;
    REP(i,0,N) {
        ll x, y, a;
        cin >> x >> y >> a;
        if(a == 1) Xl = MAX(Xl,x);
        if(a == 2) Xu = MIN(Xu,x);
        if(a == 3) Yl = MAX(Yl,y);
        if(a == 4) Yu = MIN(Yu,y);
    }

    ll yoko = MAX(Xu-Xl,0);
    ll tate = MAX(Yu-Yl,0);
    PR(tate*yoko);

    return 0;
}

/*



*/