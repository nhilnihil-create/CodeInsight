#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = ll(1e12);
const ll mod = ll(1e9+7);
const double pi = acos(-1);
#define rep0(i,n) for(ll (i) = 0; (i) < (n); ++(i))
#define rrep0(i,n) for(ll (i) = (n) - 1; (i) >= 0; --(i))
#define rep1(i,n) for(ll (i) = 1; (i) <= (n); ++(i))
#define rrep1(i,n) for(ll (i) = (n); (i) >= 1; --(i))
#define nfor(i,a,b) for(ll (i) = (a); (i) < (b); ++(i))
#define pf(x) cout << (x) << endl
#define all(x) (x).begin(),(x).end()
#define yes pf("Yes")
#define no pf("No")
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,1,-1};

ll gcd(ll a,ll b){
    if(a < b)swap(a, b);
    if(b == 0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a / g * b;
}

ll factorial(ll n){
    ll ans = 1;
    rep1(i, n){
        ans *= i;
        ans %= mod;
    }
    return ans;
}

ll power(ll a, ll b){
    ll ans = 1;
    a %= mod;
    while(b) {
        if(b & 1LL) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

//modの値の確認をすること
int main(){
    ll h,w;
    cin >> h >> w;
    vector<ll> c(26,0);
    rep0(i, h)rep0(j, w){
        char a;
        cin >> a;
        ++c[a - 'a'];
    }
    ll g1,g2,g4;
    if(h % 2 == 0 && w % 2 == 0){
        g1 = 0;
        g2 = 0;
        g4 = h * w / 4;
    }else if(h % 2 == 0){
        g1 = 0;
        g2 = h / 2;
        g4 = (h / 2) * (w / 2);
    }else if(w % 2 == 0){
        g1 = 0;
        g2 = w / 2;
        g4 = (h / 2) * (w / 2);
    }else{
        g1 = 1;
        g2 = h / 2 + w / 2;
        g4 = (h / 2) * (w / 2);
    }
    bool f = true;
    rep0(i, 26){
        if(g4 > 0){
            ll a = min(c[i] / 4,g4);
            g4 -= a;
            c[i] -= a * 4;
        }
        if(g2 > 0){
            ll a = min(c[i] / 2,g2);
            g2 -= a;
            c[i] -= a * 2;
        }
        if(g1 > 0){
            ll a = min(c[i],g1);
            g1 -= a;
            c[i] -= a;
        }
        if(c[i] > 0){
            f = false;
            break;
        }
    }
    pf(f? "Yes":"No");
    return 0;
}
