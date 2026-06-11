#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
#define P(a,b) make_pair(a,b);
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 1001001001001001001;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<pair<ll,ll>>>;


template <class T>
class SegmentTree{
  ll N;                         //葉の数
  vector<T> data;               //データを格納(要素数2*N-1)
  T def;                        //初期値かつoperationの単位元
  function<T(T,T)> operation;   //区間クエリで使う関数ラムダ式で入れる
  function<T(T,T)> update;      //一点更新で使う関数

  T _query(ll a,ll b,ll k,ll l,ll r){   //区間(a,b)を考え半開区間[l,r)が管轄
      if(b <= l || r <= a) return def;  
      if(a <= l && r <= b){
          return data[k];
      }else{
          T c1 = _query(a,b,k*2+1,l,(l+r)/2);   //左の子
          T c2 = _query(a,b,k*2+2,(l+r)/2,r);   //右の子
          return operation(c1,c2);
      }
  }
  public:
  SegmentTree(size_t _N,T _def,function<T(T,T)> _operaition,function<T(T,T)> _update):def(_def),operation(_operaition),update(_update){
          N = 1;                //N必要サイズにNを調整
          while(N < _N){
              N *= 2;
          }
          data = vector<T>(2*N-1,def);
  }

  void change(ll i,T x){
      i += N-1;
      data[i] = update(data[i],x);
      while(i > 0){
          i = (i-1)/2;
          data[i] = operation(data[i*2+1],data[i*2+2]);
      }
  }

  T query(ll a,ll b){
      return _query(a,b,0,0,N);
  }

  T operator[](ll i){
      return data[i+N-1];
  }
};

ll N,K;

int main(){
    cin >> N >> K;
    vector<ll> A(N+1),B(N+1);
    ll sum = 0;
    A[0] = 0;
    rep(i,N){
        cin >> A[i+1];
        sum += A[i+1];
        A[i+1] = sum - (i+1) * K;
    }
    map<ll,ll> mp;
    rep(i,N+1) mp[A[i]] = 0;
    ll cnt = 0;
    for(auto itr = mp.begin();itr != mp.end();itr++){
        itr -> second = cnt;
        cnt++;
    }
    rep(i,N+1){
        B[i] = mp[A[i]];
    }
    auto f = [](ll a,ll b){return a+b;};
    auto g = [](ll a,ll b){return b;};
    SegmentTree<ll> ST(200010,0,f,g);
    ll ans = 0;
    rep(i,N+1){
        ans += ST.query(0,B[i]+1);
        ST.change(B[i],ST[B[i]]+1);
    }
    cout << ans << endl;
}
