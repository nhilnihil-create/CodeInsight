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
    ll N;
    cin >> N;
    ll A[N], sum = 0;
    rep(i, N){
        cin >> A[i];
        sum += A[i];
    }
    ll S = N*(N+1)/2;
    if(sum%S != 0) {cout << "NO" << endl; return 0;}
    ll cnt = sum/S, num[N];
    rep(i, N){
        int j = (i+1)%N;
        ll d = A[i]-A[j];
        if(d+cnt < 0 || (d+cnt)%N != 0) {cout << "NO" << endl; return 0;}
        num[i] = (d+cnt)/N;
    }
    rep(i, N) cnt -= num[i];
    if(cnt == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}