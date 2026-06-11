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
    string x; cin >> x;
    vector<ll> s, t;
    ll n = x.size();
    
    ll tmp = 0; // 合計
    bool S = true; // Sを見ているか
    rep(i, n) {
        if(i == 0) {
            while(x[i] != 'S') i++;
        }
        if(S && x[i] == 'S') tmp++;
        else if(!S && x[i] == 'T') tmp++;
        else if(S && x[i] != 'S') {
            s.push_back(tmp);
            tmp = 1;
            S = false;
        }
        else if(!S && x[i] != 'T') {
            t.push_back(tmp);
            tmp = 1;
            S = true;
        }
    }
    if(!S) t.push_back(tmp);

    ll del = 0;
    rep(i, s.size()) {
        if(s[i] <= t[i]) del += s[i];
        else {
            del += t[i];
            if(i != s.size()-1) {
                s[i+1] += (s[i]-t[i]);
            }
        }
    }
    // rep(i, t.size()) cout << t[i] << endl;
    cout << n - 2*del << endl;
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
