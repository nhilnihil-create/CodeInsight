#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;

ll n, a, b, hmax;
vector<ll> h;

bool isEnough(ll x) {
    ll atack_times = 0;
    REP(i,n) {
        ll tmp = max(0LL, h[i]-b*x);
        atack_times += (tmp+a-1)/a;
    }
    return atack_times<=x;
}

ll meguru_binary_search() {
    ll ng = 0;
    ll ok = hmax/b+1;

    while(abs(ok-ng) > 1){
        ll mid = (ok+ng)/2;
        if (isEnough(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}


int main(int argc, char const *argv[]) {
    cin >> n >> a >> b;
    a-=b;
    h.resize(n);
    hmax = 0;
    REP(i,n) {
        cin >> h[i];
        if (h[i] >= hmax) hmax = h[i];
    }
    cout << meguru_binary_search() << endl;
}