#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

const int MAX_V = 1e6;

struct binary_indexed_tree{
    ll n, bit[MAX_V+1];
    //要素数N(0〜N-1)の初期化されたBITを構築
    binary_indexed_tree(int N){
        n = 1;
        while(n < N) n *= 2;
        fill_n(bit, n+1, 0);
    }
    //i番目(0から数える)の要素にx加える
    void add(int i, ll x){
        i++;
        while(i <= n){
            bit[i] += x;
            i += (i & -i);
        }
    }
    //sum(i)で[0,i)の和を取得
    ll sum(int i){
        ll s = 0;
        while(i > 0){
            s += bit[i];
            i -= (i & -i);
        }
        return s;
    }
    //query(l,r)で[l,r)の和を取得
    ll query(int l, int r){
        return sum(r) - sum(l);
    }
};

int main(){
    ll N, K;
    cin >> N >> K;
    ll a[N];
    rep(i, N) cin >> a[i];
    ll sum[N+1];
    sum[0] = 0;
    map<ll, int> mp;
    mp[0] = 0;
    rep2(i, 1, N){
        sum[i] = sum[i-1]+a[i-1]-K;
        mp[sum[i]] = 0;
    }
    int num = 0;
    for(auto &e: mp){
        mp[e.first] = num;
        num++;
    }
    binary_indexed_tree bit(num);
    ll ans = 0;
    rep(i, N+1){
        ans += bit.query(0, mp[sum[i]]+1);
        bit.add(mp[sum[i]], 1);
    }
    cout << ans << endl;
}