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

template<typename T>
struct Binary_Indexed_Tree{
    vector<T> bit;
    
    Binary_Indexed_Tree(int N){
        bit.assign(N+1, 0);
    }
    
    void add(int i, const T &x){
        for(i++; i < bit.size(); i += (i & -i)) bit[i] += x;
    }
    
    T sum(int i){
        T res = 0;
        for(i = i; i > 0; i -= (i & -i)) res += bit[i];
        return res;
    }
    
    T query(int l, int r){
        return sum(r) - sum(l);
    }
    
    void clear(){
        fill(bit.begin(), bit.end(), 0);
    }
};

int main(){
    int N; ll K;
    cin >> N >> K;
    ll a[N];
    rep(i, N) {cin >> a[i]; a[i] -= K;}
    ll sum[N+1];
    sum[0] = 0;
    rep(i, N) sum[i+1] = sum[i]+a[i];
    vector<int> v(N+1);
    iota(all(v), 0);
    sort(all(v), [&](int i, int j){
        if(sum[i] != sum[j]) return sum[i] < sum[j];
        return i < j;
    });
    Binary_Indexed_Tree<ll> bit(N);
    ll ans = 0;
    rep(i, N+1){
        ans += bit.query(0, v[i]);
        bit.add(v[i], 1);
    }
    cout << ans << endl;
}