#include <bits/stdc++.h>
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,NAME,...) NAME
#define pr(...) cerr<< GET_MACRO(__VA_ARGS__,pr8,pr7,pr6,pr5,pr4,pr3,pr2,pr1)(__VA_ARGS__) <<endl
#define pr1(a) (#a)<<"="<<(a)<<" "
#define pr2(a,b) pr1(a)<<pr1(b)
#define pr3(a,b,c) pr1(a)<<pr2(b,c)
#define pr4(a,b,c,d) pr1(a)<<pr3(b,c,d)
#define pr5(a,b,c,d,e) pr1(a)<<pr4(b,c,d,e)
#define pr6(a,b,c,d,e,f) pr1(a)<<pr5(b,c,d,e,f)
#define pr7(a,b,c,d,e,f,g) pr1(a)<<pr6(b,c,d,e,f,g)
#define pr8(a,b,c,d,e,f,g,h) pr1(a)<<pr7(b,c,d,e,f,g,h)
#define prArr(a) {cerr<<(#a)<<"={";int i=0;for(auto t:(a))cerr<<(i++?", ":"")<<t;cerr<<"}"<<endl;}
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
template<class T1, class T2, class T3> ostream& operator<<(ostream& o,tuple<T1,T2,T3> t){
  return o<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
template<class T1, class T2> istream& operator>>(istream& i,pair<T1,T2> &p){return i>>p.first>>p.second;}
template<class T> ostream& operator<<(ostream& o,vector<T> a){Int i=0;for(T t:a)o<<(i++?" ":"")<<t;return o;}
template<class T> istream& operator>>(istream& i,vector<T> &a){for(T &t:a)i>>t;return i;}
//INSERT ABOVE HERE

int K;
vector<vector<int> > G;
vector<int> par;


int ans;
int dfs(int pos){
  int mx = 0;
  for(int to:G[pos]){
    if(to == par[pos]) continue;
    mx = max(mx, dfs(to) + 1);
  }
  
  if(par[pos] != 0 && mx == K-1){ans++; mx = -1;}
  return mx;
}


signed main(){
  srand((unsigned)time(NULL));
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int N;
  cin>>N>>K;

  G.resize(N);
  par.resize(N);

  int ofset = 0;
  for(int i=0;i<N;i++){
    int a;
    cin>>a; a--;
    if(i == 0) {
      ofset = (a != 0);
      continue;
    }
    par[i] = a;
    G[i].push_back(a);
    G[a].push_back(i);
  }

  dfs(0);
  cout<<ans + ofset<<endl;
  
  return 0;
}
