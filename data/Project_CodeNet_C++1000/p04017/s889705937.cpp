#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0;i<(n);++i)
using ll = long long;
using pll = pair<ll,ll>;
constexpr ll INF = (1LL<<60);
constexpr ll MOD = (1e9+7);
//constexpr ll MOD = (998244353);
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}
void dump(){cout<<endl;}
template<class T,class... Ts> void dump(T&& h, Ts&&... t){cout<<h<<", ";dump(forward<Ts>(t)...);}
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}

void solve1();void solve2();
int main(){
  solve1();
  return 0;
}

struct doubling{
  ll n,log_n;
  vector<vector<ll>> table;
  doubling(){}
  doubling(vector<ll>const& a,ll l){
    n = a.size();
    log_n = floor(log2(n));
    table = vector<vector<ll>>(log_n,vector<ll>(n,-1));

    rep(i,n){
      ll key = a[i]+l;
      auto itr = upper_bound(a.begin(),a.end(),key);
      itr--;
      ll idx = itr-a.begin();
      table[0][i] = idx;
    }
    for(ll i=1;i<log_n;++i){
      for(ll j=0;j<n;++j){
        //if(a[j]<((1LL<<i)*l))table[i][j]=-1;
        table[i][j] = table[i-1][table[i-1][j]];
      }
    }
  }
  void dump(){
    for(auto y:table){
      for(auto x:y)cout<<x<<" ";
      cout<<endl;
    }
  }
  ll search(ll j,ll val){
    ll low=0,high=log_n;
    while(high-low>1){
      ll mid = (high+low)>>1;
      if(table[mid][j]<val)low=mid;
      else high=mid;
    }
    return low;
  }
  ll calc(ll a,ll b){
    if(a>b)swap(a,b);
    ll res = 0;
    while(a<b){
      ll k = search(a,b);
      res += (1LL<<k);
      a = table[k][a];
    }
    return res;
  }
};

void solve1(){

  ll n;
  cin>>n;
  vector<ll> a(n);
  cin>>a;
  ll l,q;
  cin>>l>>q;
  vector<pll>ab(q);
  cin>>ab;

  doubling d(a,l);
  //d.dump();
  for(auto& x:ab){
    ll a,b;tie(a,b)=x;
    a--;b--;
    ll res = d.calc(a,b);
    cout<<(res)<<endl;
  }

}