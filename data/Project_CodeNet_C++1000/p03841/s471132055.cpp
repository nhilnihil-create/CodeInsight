#include <bits/stdc++.h>
#ifdef LOCAL_DEBUG
#define DEBUG 1
#define CERR if(DEBUG) cerr
#define MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,NAME,...) NAME
#define pr(...) CERR<<MACRO(__VA_ARGS__,pr10,pr9,pr8,pr7,pr6,pr5,pr4,pr3,pr2,pr1)(__VA_ARGS__)<<endl
#define pr1(a) (#a)<<"="<<(a)<<" "
#define pr2(a,b) pr1(a)<<pr1(b)
#define pr3(a,b,c) pr1(a)<<pr2(b,c)
#define pr4(a,b,c,d) pr1(a)<<pr3(b,c,d)
#define pr5(a,b,c,d,e) pr1(a)<<pr4(b,c,d,e)
#define pr6(a,b,c,d,e,f) pr1(a)<<pr5(b,c,d,e,f)
#define pr7(a,b,c,d,e,f,g) pr1(a)<<pr6(b,c,d,e,f,g)
#define pr8(a,b,c,d,e,f,g,h) pr1(a)<<pr7(b,c,d,e,f,g,h)
#define pr9(a,b,c,d,e,f,g,h,i) pr1(a)<<pr8(b,c,d,e,f,g,h,i)
#define pr10(a,b,c,d,e,f,g,h,i,j) pr1(a)<<pr9(b,c,d,e,f,g,h,i,j)
#define prArr(a){CERR<<(#a)<<"={";int i=0;for(auto t:(a))CERR<<(i++?", ":"")<<t;CERR<<"}"<<endl;}
#else
#define DEBUG 0
#define pr(...)
#define prArr(a)
#endif
using namespace std;
using Int = long long;
using _int = int;
using ll = long long;
using Double = long double;
const Int INF = (1LL<<60)+1e9; // ~ 1.15 * 1e18
const Int mod = (1e9)+7;
const Double EPS = 1e-8;
const Double PI = 6.0 * asin((Double)0.5);
using P = pair<Int,Int>;
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
template<class T1, class T2> ostream& operator<<(ostream& o,pair<T1,T2> p){return o<<"("<<p.first<<","<<p.second<<")";}
template<class T1, class T2, class T3> ostream& operator<<(ostream& o,tuple<T1,T2,T3> t){return o<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
template<class T1, class T2> istream& operator>>(istream& i,pair<T1,T2> &p){return i>>p.first>>p.second;}
template<class T> ostream& operator<<(ostream& o,vector<T> a){Int i=0;for(T t:a)o<<(i++?" ":"")<<t;return o;}
template<class T> istream& operator>>(istream& i,vector<T> &a){for(T &t:a)i>>t;return i;}
//INSERT ABOVE HERE


signed main(){
  srand((unsigned)time(NULL));
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  Int N;
  cin>>N;
  vector<Int> X(N);
  cin>>X;
  for(Int &x:X) x--;

  vector<P> A(N);
  for(Int i=0;i<N;i++) A[i] = P(X[i], i);
  sort(A.begin(), A.end());


  vector<Int> used(N * N);
  vector<Int> ans(N * N);
  for(Int i=0;i<N;i++) used[ X[i] ] = 1, ans[ X[i] ] = i + 1;

  Int l = 0;
  for(Int i=0;i<N;i++){
    Int x, a; tie(x, a) = A[i];
    for(Int j=0;j<a;j++){
      while(l < N * N && used[l]) l++;
      if(l > x){cout<<"No"<<endl;return 0;}
      ans[l] = a + 1;
      used[l] = 1;
    }
  }
  Int r = N * N - 1;
  for(Int i=N-1;i>=0;i--){
    Int x, a; tie(x, a) = A[i];
    for(Int j=0;j<N - 1 - a;j++){
      while(r >= 0 && used[r]) r--;
      if(r < x){cout<<"No"<<endl;return 0;}
      ans[r] = a + 1;
      used[r] = 1;
    }
  }

  cout<<"Yes"<<endl;
  cout<<ans<<endl;

  return 0;
}
