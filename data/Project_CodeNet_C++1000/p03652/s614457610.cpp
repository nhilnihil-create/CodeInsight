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


int main() {
    ll n, m, ans = INF; cin >> n >> m;
    set<ll> sport; // 開催されるスポーツ
    rep(i, m) sport.insert(i);

    vector<vector<ll>> a(n, vector<ll>(m));

    rep(i, n) {
        rep(j, m) {
            ll tmp; cin >> tmp;
            tmp--;
            a[i][j] = tmp;
        }
    }

    if(m == 1) {
        cout << n << endl;
        return 0;
    }
    // スポーツを一つずつ減らしていく
    rep(i, m-1) {
        ll tmp = 0, s = -1;
        vector<ll> num(m, 0);
        // 各人が参加するスポーツを消える
        rep(j, n) {
            rep(k, m) {
                if(sport.count(a[j][k])) {
                    num[a[j][k]]++;
                    break;
                }
            }
        }
        // 最大のスポーツを見て除外
        rep(j, m) {
            if(tmp < num[j] && sport.count(j)) {
                tmp = num[j];
                s = j;
            }
        }
        if(ans > tmp) ans = tmp;
        sport.erase(s);
    }

    cout << ans << endl;

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
