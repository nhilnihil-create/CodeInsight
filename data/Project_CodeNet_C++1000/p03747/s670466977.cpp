#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    ll N, L, T;
    cin >> N >> L >> T;
    ll x[N]; int w[N];
    rep(i, N){
        cin >> x[i] >> w[i];
    }
    ll cnt = 0;
    ll a = (2*T)/L, b = (2*T)%L;
    if(w[0] == 1){
        vector<int> v;
        rep(i, N){
            if(w[i] == 2) v.pb(x[i]-x[0]);
        }
        cnt = a*sz(v);
        for(auto &e: v) if(e < b) cnt++;
        cnt %= N;
    }
    else{
        vector<int> v;
        rep(i, N){
            if(w[i] == 1) v.pb(L+x[0]-x[i]);
        }
        cnt = a*sz(v);
        for(auto &e: v) if(e <= b) cnt++;
        cnt %= N;
        cnt = (N-cnt)%N;
    }
    ll res[N];
    rep(i, N){
        if(w[i] == 1) res[i] = (x[i]+T)%L;
        else res[i] = (x[i]+L*T-T)%L;
    }
    ll pos = res[0];
    sort(res, res+N);
    int id = 0;
    rep(i, N){
        if(res[i] == pos) {id = i; break;}
    }
    rep(i, N){
        cout << res[(N+id-cnt+i)%N] << endl;
    }
}