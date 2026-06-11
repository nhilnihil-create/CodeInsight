#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>

using namespace std;
using ll = long long;

#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
/*----------------------------------------------------------------------------------*/

const ll mod = 1e9+7;

ll get_mod (ll a) {
    if (a >= 0) a %= mod;
    else {
        while (a < 0) {
            a += mod;
        }
    }
    return a;
}

int main() {
    int n, m; cin >> n >> m;
    vector<ll> x(n), y(m);
    rep(i,n) cin >> x[i];
    rep(i,m) cin >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    ll sumx = 0, sumy = 0;
    rep(i,n) {
        sumx += x[i]*i%mod;
        sumx = get_mod(sumx);

        sumx -= x[i]*(n-i-1);
        sumx = get_mod(sumx);
    }

    rep(i,m) {
        sumy += y[i]*i%mod;
        sumy = get_mod(sumy);

        sumy -= y[i]*(m-i-1);
        sumy = get_mod(sumy);
    }

    cout << sumx*sumy%mod << endl;
    return 0;
}
