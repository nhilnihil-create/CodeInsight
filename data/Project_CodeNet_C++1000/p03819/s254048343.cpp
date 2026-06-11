#include<bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using vt = vector<T>;
template<class T> using vvt = vector<vt<T>>;
template<class T> using ttt = tuple<T,T>;
using tii = tuple<int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define mt make_tuple
#define ALL(a) (a).begin(),(a).end()
#define FST first
#define SEC second
#define DEB cerr<<"!"<<endl
#define SHOW(a,b) cerr<<(a)<<" "<<(b)<<endl
#define DIV ll(1e9+7)
const int INF = (INT_MAX/2);
const ll LLINF = (LLONG_MAX/2);
const double eps = 1e-8;
//const double PI = M_PI;  
inline ll pow(ll x,ll n,ll m){ll r=1;while(n>0){if((n&1)==1)r=r*x%m;x=x*x%m;n>>=1;}return r%m;}
inline ll lcm(ll d1, ll d2){return d1 / __gcd(d1, d2) * d2;}
// IT 5000兆　欲しい
/* Coding space */
template<class T>
struct FT{
    vector<T> d;
    FT(size_t n):d(n+1){}
    T sum(size_t i){T s{};for(++i;i>0;i-=i&-i)s+=d[i];return s;}
    T sum(size_t i,size_t j){return i?sum(j)-sum(i-1):sum(j);}
    void add(size_t i,T x){for(++i;i<d.size();i+=i&-i)d[i]+=x;}
    void add(size_t i, size_t j,T x){add(i,x); add(j+1,-x);}
};
template<class T>
struct lazy_FT{
  FT<T> d,lazy; // value, lazy array
  lazy_FT(size_t n):d(n+1),lazy(n+1){}
  void add(size_t l, size_t r,T val){ // log(n)
    d.add(l, r, val);
    lazy.add(l, r, (l - 1) * val);
    lazy.add(r + 1, (-r + l - 1) * val);
  }
  T sum(size_t i){return d.sum(i) * i - lazy.sum(i);} // log(n)  sum(0 to i)
  T sum(size_t i, size_t j){return sum(j) - sum(i-1);} // log(n)
};
int main(){
  int n,m; cin >> n >> m;
  lazy_FT<int> bit(1000000);
  using Data = tuple<int,int,int>; // Dist,l,r
  vt<Data> data;
  rep(i,n){
    int l,r; cin >> l >> r;
    data.pb(Data{r-l+1,l,r});
  }
  sort(ALL(data));

  int index = 0;
  for(int i = 1; i <= m; i++){
    int a,b,c; tie(a,b,c) = data[index];
    //SHOW(i,a);
    while(i > a && index < n){
      //cerr << i << " " << a << " " << b << " " <<  c << endl;
      bit.add(b,c,1);
      index++;
      if(index >= n) break;
      tie(a,b,c) = data[index];
    }
    
    int ans = n - index;
    for(int j = 0; j <= m; j += i)
      ans += bit.sum(j,j);
    cout << ans << endl;
  }
}