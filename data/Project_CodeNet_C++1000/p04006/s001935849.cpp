#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define vtpl(x,y,z) vector<tuple<x,y,z>>
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
} 

template <class T>
class SegTree {
    int n;// 葉の数
    vector<T> data;// データを格納するvector
    T def; // 初期値かつ単位元
    function<T(T, T)> operation; // 区間クエリで使う処理
    function<T(T, T)> update;// 点更新で使う処理

    // 区間[a,b)の総和。ノードk=[l,r)に着目している。
    T _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return def; // 交差しない
        if (a <= l && r <= b)
            return data[k]; // a,l,r,bの順で完全に含まれる
        else {
            T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子
            T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子
            return operation(c1, c2);
        }
    }

    public:
    // _n:必要サイズ, _def:初期値かつ単位元, _operation:クエリ関数,
    // _update:更新関数
    SegTree(size_t _n, T _def, function<T(T, T)> _operation,
        function<T(T, T)> _update)
        : def(_def), operation(_operation), update(_update) {
        n = 1;
        while (n < _n) {
            n *= 2;
        }
        data = vector<T>(2 * n - 1, def);
    }

    // 場所i(0-indexed)の値をxで更新
    void change(int i, T x) {
        i += n - 1;
        data[i] = update(data[i], x);
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    // [a, b)の区間クエリを実行
    T query(int a, int b) {
        return _query(a, b, 0, 0, n);
    }

    // 添字でアクセス
    T operator[](int i) {
        return data[i + n - 1];
    }
};

int main(){
    ll n,t;cin >> n >>t;
    SegTree<ll> st(2*n,INF,[](ll a,ll b){return min(a,b);},[](ll a,ll b){return b;});
    rep(i,n){
        ll a;cin >> a;
        st.change(i,a);
        st.change(i+n,a);
    }
    ll ans=INF;
    rep(i,n){
        ll ret=0;
        rep(j,n){
            //cout << st.query(j+n-i,j+n+1) <<endl;
            ret+=st.query(j+n-i,j+n+1);
        }
        //cout << ret+t*i <<endl;
        chmin(ans,ret+t*i);
    }
    cout << ans <<endl;
}