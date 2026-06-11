#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)

//Monoid, 1点更新(書き換え)区間取得
//要素数, 2項演算, 単位元 (, 初期データ)
//todo:1点取得も関数化する？
template<typename T>
struct SegmentTree{
    typedef function<T(T,T)> F;
    int n;    //要素数
    F f;    //2項演算
    T e;    //単位元
    vector<T> dat;
    SegmentTree(int n_,F f,T e):f(f),e(e){
        init(n_);
        build();
    }
    SegmentTree(int n_,F f,T e,vector<T>& v):f(f),e(e){
        init(n_);
        build(n_,v);
    }
    void init(int n_){
        n=1;
        while(n<n_)n<<=1;
        dat.clear();
        dat.resize(n<<1, e);
    }
    void build(int n_,const vector<T>& v){
        for(int i=0;i<n_;++i)dat[n+i]=v[i];
        build();
    }
    void build(){
        for(int i=n-1;i>=1;--i){
            dat[i] = f(dat[i<<1],dat[i<<1|1]);
        }
    }
    void update(int k,const T& x){
        dat[k+=n]=x;
        while(k>>=1){
            dat[k] = f(dat[k<<1],dat[k<<1|1]);
        }
    }
    int query(int a,int b){
        T l=e,r=e;
        for(a+=n,b+=n;a<b;a>>=1,b>>=1){
            if(a&1)l=f(l,dat[a++]);
            if(b&1)r=f(dat[--b],r);
        }
        return f(l,r);
    }
};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int32 n,x;
  cin >> n >> x;
  vector<int32> a(n);
  REP(i,n)cin >> a[i];
  SegmentTree<int32> rmq(n,[](int32 a, int32 b){return min(a,b);},INF,a);
  int64 ans = LLINF;
  REP(magic,n){
    int64 cur = (int64)x * magic;
    REP(i,n){
      if(i-magic < 0){
        cur += min(rmq.query(0,i+1), rmq.query(i-magic+n,n));
        // cout << 0 << " " << i + 1 << " " << i-magic+n << " " << n << endl;
      }else{
        cur += rmq.query(i-magic,i+1);
        // cout << i-magic << " " << i+1 << endl;
      }
    }
    // ANS(cur);
    ans = min(ans, cur);
  }
  ANS(ans);
  return 0;
}