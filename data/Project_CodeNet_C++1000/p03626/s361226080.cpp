#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1LL<<62;
const int MAX = 1e5;

//mod(1e9+7)
const int mod = 1e9+7;
struct mint {
    ll x;
    mint(ll x = 0) : x(x % mod){}
    mint &operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint &operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint &operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }
};

int main() {
    int n; cin >> n;
    vector<string> field(2);
    rep(i,2) cin >> field[i];
    int id = 0;
    vint x;
    while (id < n) {
        if (field[0][id] == field[1][id]) {
            x.push_back(1);
            id++;
        }
        else {
            x.push_back(0);
            id += 2;
        }
    }
    mint sum = 0;
    if (x[0] == 1) sum += 3;
    else sum += 6;
    REP(i,x.size()) {
        if (x[i] == 1 && x[i-1] == 1) sum *= 2;
        if (x[i] == 0 && x[i-1] == 1) sum *= 2;
        if (x[i] == 0 && x[i-1] == 0) sum *= 3;
    }
    cout << sum.x << endl;
}