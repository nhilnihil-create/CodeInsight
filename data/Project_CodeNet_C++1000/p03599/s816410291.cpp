#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;


#define rep(i,n) for(ll (i)=0; (i)<(ll)(n); (i)++)
#define frep(i,m,n) for(ll (i)=(m); (i)<=(ll)(n); (i)++)
#define rrep(i,n) for(ll (i)=(n)-1; (i)>-1; (i)--)
#define frrep(i,m,n) for(ll (i)=(n); (i)>(ll)(m); (i)--)
#define ALL(x) (x).begin(), (x).end()

const ll INF = 100100100100100100;
const ll MOD = 1000000007;

// get abs
ll my_abs(ll a);
// a^n
ll a_n(ll a, ll n);
// get gcd
ll my_gcd(ll a, ll b);
// a^(-1) % MOD 
ll inv(ll a);
// (a+b+c)%MOD
ll madd(ll a, ll b, ll c);
// (a-b)%MOD
ll msub(ll a, ll b);
// (a*b*c)%MOD
ll mtime(ll a, ll b, ll c);

ll a, b, c, d, e, f;
vector<ll> water, sugar;
set<ll> w, s;

void water_list(ll now) {
    if(!w.count(now+a) && now+a <= f/100) {
        w.insert(now+a);
        water.push_back(now+a);
        water_list(now+a);
    }
    if(!w.count(now+b) && now+b <= f/100) {
        w.insert(now+b);
        water.push_back(now+b);
        water_list(now+b);
    }
}

void sugar_list(ll now) {
    if(!s.count(now+c) && now+c <= f/2) {
        s.insert(now+c);
        sugar.push_back(now+c);
        sugar_list(now+c);
    }
    if(!s.count(now+d) && now+d <= f/2) {
        s.insert(now+d);
        sugar.push_back(now+d);
        sugar_list(now+d);
    }
}


int main() {
    cin >> a >> b >> c >> d >> e >> f;
    sugar.push_back(0);
    water_list(0);
    sugar_list(0);

    ll ans_w = 1, ans_s = 0;

    rep(i, water.size()) {
        rep(j, sugar.size()) {
            // 容量オーバー
            if(100*water[i] + sugar[j] > f) continue;
            // 溶け残り
            if(e*(100*water[i]+sugar[j]) < (100+e)*sugar[j]) continue;
            if(sugar[j]*(100*ans_w+ans_s) >= ans_s*(100*water[i]+sugar[j])) {
                ans_w = water[i];
                ans_s = sugar[j];
            }
        }
    }

    cout << 100*ans_w + ans_s << " " << ans_s << endl; 

    return 0;
}

ll my_abs(ll a) {
    if(a >= 0) return a;
    else return -1 *a;
}

ll a_n(ll a, ll n) { 
    if(n == 0) return 1;
    
    ll ret = a, count = 1;
    while(count * 2 < n) {
        ret *= ret;
        count *= 2;
    }
    if(count == n) return ret;
    else return (ret * a_n(a, n-count));
}

ll my_gcd(ll a, ll b) {
    if(b == 0) return a;
    return my_gcd(b, a%b);
}

ll inv(ll a) {
    return a_n(a, MOD-2);
}

ll madd(ll a, ll b, ll c) {
    ll ret = (a+b) % MOD;
    return (ret+c) % MOD;
}

ll msub(ll a, ll b) {
    if(a < b) return (a-b+MOD) % MOD;
    else return (a-b) % MOD;
}

ll mtime(ll a, ll b, ll c) {
    ll ret = (a*b) % MOD;
    return (ret*c) % MOD;
}
