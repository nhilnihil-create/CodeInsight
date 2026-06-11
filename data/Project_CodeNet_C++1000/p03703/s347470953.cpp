#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
ll INF = 1LL<<60;
ll M = 1000000007;

struct fenwick_tree {
    typedef int T;
    T n;
    vector<T> bit;

    // 各要素の初期値は 0
    fenwick_tree(T num) : bit(num+1, 0) { n = num; }

    // a_i += w
    void add(T i, T w) {
        for (T x = i; x <= n; x += x & -x) {
            bit[x] += w;
        }
    }
    // [1, i] の和を計算.
    T sum(T i) {
        T ret = 0;
        for (T x = i; x > 0; x -= x & -x) {
            ret += bit[x];
        }
        return ret;
    }
    // [left+1, right] の和を計算.
    T sum(T left, T right) {
        return sum(right) - sum(left);
    }
};

int main(){
    ll N, K; cin >> N >> K;
    vll a(N);
    rep(i, 0, N){
        cin >> a[i];
    }
    vll b(N);
    rep(i, 0, N){
        b[i] = a[i] - K;
    }   
    ll s = 0;
    vll asum(N+1);
    asum[0] = 0;
    ll mn = 0;
    rep(i, 1, N+1){
        s += b[i-1];
        asum[i] = s;
        mn = min(s, mn);
    }
    if(mn < 1){
        rep(i, 0, N+1){
            asum[i] += abs(mn)+1;
        }
    }
    Map m;
    vll v = asum;
    sort(v.begin(),v.end());
    ll t = 0;
    rep(i, 0, N+1){
        if(m.find(v[i]) == m.end()){
            m[v[i]] = t+1;
            t++;
        }else{
            continue;
        }
    }
    rep(i, 0, N+1){
        asum[i] = m[asum[i]];
    }
    fenwick_tree ftree(1000001);
    ll ans = 0;
    rrep(i, N, -1){
        ans += ftree.sum(asum[i]-1, 1000001);
        ftree.add(asum[i], 1);
    }
    prt(ans);
}