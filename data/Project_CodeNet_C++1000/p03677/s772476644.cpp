// G++ MACRO.CPP -STD=C++17
#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
 
#define dump(x)  cout << #x << " = " << (x) << endl;
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) << endl
#define possible(n) cout << ((n) ? "possible" : "impossible"  ) << endl
 
#define SANKOU(n,a,b) cout << ((n) ? (#a) : (#b) ) << endl
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
 
#define FOREACH(x,a) for(auto& (x) : (a) )
 
#define WFA(d,v) REP(k,v)REP(i,v)REP(j,v)d[i][j]=min(d[i][j],d[i][k]+d[k][j])
 
#define SCOUT(x) cout<<(x)<<" "
#define ENDL cout<<endl
 
#define VECCIN(x) for(auto&youso_: (x) )cin>>youso_
#define VECIN2(x,y) REP(i,x.size())cin>>x[i]>>y[i]
#define VECCOUT(x) if(1){for(auto tt=x.begin();tt!=x.end();tt++){if(tt!=x.begin())cout<<" ";cout<<(*tt);}cout<<endl;}
 
#define ALL(obj) (obj).begin(),(obj).end()
 
#define EXIST(n,x) (find(ALL(n),x)!=n.end())
#define UNIQUE(obj) sort(ALL( obj )); obj.erase(unique(ALL(obj)),obj.end())
#define EN(x) if(1){cout<<#x<<endl;return 0;}
#define COUT(x) cout<<(x)<<endl
void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail){
    cin>>head;
    CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) ll __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)
 
template <class T = ll>
T IN(){T x;cin>>x;return (x);}
 
template <class Head>
void VT(Head head){}
template <class Head,class Seco,class... Tail>
void VT(Head&& head,Seco&& seco,Tail&&... tail){
    seco.resize(head);
    VT(head,move(tail)...);
}
void VT2(){}
template <class Head,class... Tail>
void VT2(Head&& head,Tail&&... tail){
  VECCIN(head);
  VT2(move(tail)...);
}
 
template <class Head>
void VT3(Head&& head){}
template <class Head,class Seco,class... Tail>
void VT3(Head&& head,Seco&& seco,Tail&&... tail){
  seco[head]=IN();
  VT3(head,move(tail)...);
}
 
#define VC1(n,...) V __VA_ARGS__;VT(n,__VA_ARGS__);VT2(__VA_ARGS__); //aaabbbccc
#define VC2(n,...) V __VA_ARGS__;VT(n,__VA_ARGS__);REP(i,n)VT3(i,__VA_ARGS__); //abcabcabc
 
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision; // cpp_int
 
#define P pair<ll,ll>
#define V vector<ll>
#define M map<ll,ll>
#define S set<ll>
 
#define pb(a) push_back(a)
#define mp make_pair

int main(){

  CIN(n,m);
  V a(n);
  REP(i,n)scanf("%d",&a[i]);
  REP(i,n)a[i]--;


  V ad(m*2,0);
  V num(m*2,0);

  FOR(i,1,n){
    int st = a[i-1]+2;
    int en = (a[i-1]>a[i]?a[i]+m:a[i]);
    //dump(st);dump(en);

    //ad[st]++;
    num[st]++;
    ad[en+1]-=(en-st+1);
    num[en+1]--;
  }
  FOR(i,1,2*m)
    num[i]+=num[i-1];

  /*
  VECCOUT(ad);
  VECCOUT(num);
  */

  V rui(2*m,0);
  rui[0]=num[0];
  FOR(i,1,2*m)
    rui[i]=rui[i-1]+ad[i]+num[i];

  // VECCOUT(rui);
  V ansv(m,0);
  REP(i,m)
    ansv[i]=rui[i]+rui[i+m];
  // VECCOUT(ansv);

  ll ma = 0;
  FOR(i,1,n)
    ma+=(a[i]-a[i-1]+m)%m;
  //COUT(ma);
  COUT(ma-*max_element(ALL(ansv)));


  /*
  アドが取れる始点と終点を出す
  ex: 1 5 1 4 m=6なら
  3-5,1,3-4になる
  そこの始点(3-5なら3)に1を足して、終点+1(3-5なら6)に-(範囲の長さ+1)を足す(3-5なら-4)

  1ずれるので 0 4 0 3 : 2-4,0,2-3

  */



  return 0;
}