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
    ll h, w; cin >> h >> w;
    map<string, ll> m;
    priority_queue<ll> que;
    rep(i, h) {
        string s; cin >> s;
        rep(j, w) {
            string tmp = s.substr(j, 1);
            if(m.count(tmp)) m[tmp]++;
            else m[tmp] = 1;
        }
    }
    for(auto p: m) {
        auto value = p.second;
        que.push(value);
    }
    rep(i, (h/2)*(w/2)) {
        ll num = que.top();
        que.pop();
        if(num < 4) {
            cout << "No" << endl;
            return 0;
        }
        else {
            num -= 4;
            if(num > 0) que.push(num);
        }
    }

    if((h%2) == 0 && (w%2) == 0) {
        cout << "Yes" << endl;
        return 0;
    }
    else if((h%2) == 0 && (w%2) == 1) {
        rep(i, h/2) {
            ll num = que.top();
            que.pop();
            if(num < 2) {
                cout << "No" << endl;
                return 0;
            }
            else {
                num -= 2;
                if(num > 0) que.push(num);
            }
        }
    }
    else if((h%2) == 1 && (w%2) == 0) {
        rep(i, w/2) {
            ll num = que.top();
            que.pop();
            if(num < 2) {
                cout << "No" << endl;
                return 0;
            }
            else {
                num -= 2;
                if(num > 0) que.push(num);
            }
        }
    }
    else {
        rep(i, (h/2)+(w/2)) {
            ll num = que.top();
            que.pop();
            if(num < 2) {
                cout << "No" << endl;
                return 0;
            }
            else {
                num -= 2;
                if(num > 0) que.push(num);
            }
        }
    }
    
    cout << "Yes" << endl;    

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
