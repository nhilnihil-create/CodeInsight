#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(i) begin(i), end(i)

const int INF = 0x3fffffff;
const ll MINF = 0x7fffffffffff;
const ld DINF = numeric_limits<ld>::infinity();
const int MOD = 1000000007;
const int MODD = 998244353;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932;

template<class T> bool chmin(T &a, const T &b){ if(a > b){ a = b; return 1; } else return 0; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } else return 0; }
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }

ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
ll pow_mod(ll n,ll k,ll m){ll r = 1;for(; k > 0;k >>= 1) {if (k & 1) r = (r * n) % m; n = (n * n) % m;}return r;}

//ここから。
int main(){
    int H,W;
    cin >> H >> W;
    vector<int> alf(26,0);
    rep(i,H*W){
        char a;
        cin >> a;
        alf[a - 'a']++;
    }
    int ecnt,qcnt,ocnt;
    ecnt = qcnt = ocnt = 0;
    rep(i,26){
        if(alf[i] % 4 == 0){
            qcnt++;
        }else if(alf[i] % 2 == 0){
            ecnt++;
        }else{
            ocnt++;
            if((alf[i] - 1) % 4 == 0){
                qcnt++;
            }else{
                ecnt++;
            }
        }
    }
    bool state = false;
    if(H%2 == 1 && W%2 == 1){
        if(ocnt == 1 && ecnt <= (H+W-2)/2) state = true;    
    }else if(H%2 == 1 && W%2 == 0){
        if(ocnt == 0 && ecnt <= W/2) state = true;
    }else if(H%2 == 0 && W%2 == 1){
        if(ocnt == 0 && ecnt <= H/2) state = true;
    }else{
        if(ocnt == 0 && ecnt == 0) state = true;
    }
    if(state) cout << "Yes" << endl;
    else cout << "No" << endl;
}