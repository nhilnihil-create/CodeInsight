#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

//抽象化したセグメント木
//SegmentTree<T>(n,fx,ex):モノイド(集合T,二項演算fx, 単位元ex)についてサイズnで構築
template<typename T>
struct  SegmentTree{
    using FX = function<T(T,T)>;
    ll n;
    FX fx;
    const T ex;
    vector<T>node;

    //初期化(datは単位元exで初期化する)
    SegmentTree(ll n_, FX fx_, T ex_) : n(),fx(fx_),ex(ex_),node(n_*4,ex_){
        ll x = 1;
        while(n_ > x)x*=2;
        n = x;
    }
    
    void set(ll i, T x){//最下段の要素の構築
        node[i+n-1]=x;
    }

    void build(){
        for(ll i=n-2;i>=0;i--){
            node[i]=fx(node[2*i+1],node[2*i+2]);
        }
    }

    //i番目の要素の更新,計算量O(log(n))
    void update(ll i, T x){
        i += n-1;
        node[i]=x;
        while(i>0){
            i=(i-1)/2;
            node[i]=fx(node[i*2+1],node[i*2+2]);
        }
    }

    //query(a,b)は[a,b)全てにfxを作用させた値の取得,計算量はO(log(n))
    T query(ll a,ll b){
        return query_sub(a,b,0,0,n);
    }

    T query_sub(ll a,ll b,ll k,ll l,ll r){
        if(r<=a || b<=l){//区間が全くかぶらない時は単位元を返す
            return ex;
        }
        if(a<=l && r <= b){//区間を完全に覆っている時
            return node[k];
        }
        T vl = query_sub(a,b,k*2+1,l,(l+r)/2);
        T vr = query_sub(a,b,k*2+2,(l+r)/2,r);
        return fx(vl,vr);
    }

    T operator[](ll i){
        return node[i+n-1];
    }

    void print(){
        for(ll i=0;i<n;i++){
            cout << (*this)[i];
            if(i != n-1)cout << ',';
        }
        cout << endl;
    }

    //二分探索で[a,b)でx以下の値を持つ最右の要素位置を見つける
    //コメントアウトするとx以上にもできる
    //全てx以下なら-1を返す
    //後々抽象化出来たらいいな
    ll find_right(ll a,ll b,ll x,ll k,ll l,ll r){
        if(node[k]>x||r<=a||b<=l)return -1;
        //if(node[k]<x||r<=a||b<=l)return -1;
        if(k>=n-1)return (k-(n-1));
        ll rv = find_right(a,b,x,2*k+2,(l+r)/2,r);
        if(rv!=-1)return rv;
        return find_right(a,b,x,2*k+1,l,(l+r)/2);
    }

    ll find_right(ll a,ll b,ll x){
        return find_right(a,b,x,0,0,n);
    }

    //二分探索で[a,b)でx以下の値を持つ最左の要素位置を見つける
    //コメントアウトするとx以上にもできる
    //全てx以下なら-1を返す
    ll find_left(ll a,ll b,ll x,ll k,ll l,ll r){
        if(node[k]>x||r<=a||b<=l)return -1;
        //if(node[k]<x||r<=a||b<=l)return -1;
        if(k>=n-1)return (k-(n-1));
        ll lv = find_left(a,b,x,2*k+1,l,(l+r)/2);
        if(lv!=-1)return lv;
        return find_left(a,b,x,2*k+2,(l+r)/2,r);
    }

    ll find_left(ll a,ll b,ll x){
        return find_left(a,b,x,0,0,n);
    }
};

/*関数の定義にはラムダ式を使う
RMQなら
auto fx = [](ll x1,ll x2) -> ll{
    return min(x1,x2);
};
ll ex = numeric_limits<ll>::max();
SegmentTree<ll> rmq(n,fx,ex);

のように使う*/


//入力
ll n;
vector<ll>a;



int main(){
    cin >> n;
    a.resize(n);
    rep(i,n)cin>>a[i];
    auto fx = [](ll x1,ll x2) -> ll{
        return min(x1,x2);
    };
    ll ex = numeric_limits<ll>::max();
    SegmentTree<ll> seg(n,fx,ex);
    rep(i,n){
        seg.set(i,a[i]);
    }
    seg.build();
    ll ans = 0;
    rep(i,n){
        ll left = seg.find_right(0,i,a[i]);
        ll right = seg.find_left(i+1,n,a[i]);
        if(right==-1)right=n;
        ans += ((i-left)*(right-i))*a[i];
    }
    cout << ans << endl;
    return 0;
    
}