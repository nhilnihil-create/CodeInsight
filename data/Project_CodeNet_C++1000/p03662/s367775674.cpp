#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <tuple>
#include <utility>
#include <vector>
#define ll long long
#define itn int
#define endl '\n'
#define co(ans) cout<<ans<<endl
#define COYE cout<<"YES"<<endl
#define COYe cout<<"Yes"<<endl
#define COye cout<<"yes"<<endl
#define CONO cout<<"NO"<<endl
#define CONo cout<<"No"<<endl
#define COno cout<<"no"<<endl
#define FORE(i,a) for(auto &i:a)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,1,n)
#define PB push_back
#define MP make_pair
#define ALL(V) (V).begin(),(V).end()
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define EACH(V,i) for(typeof((V).begin()) i=(V).begin();i!=(V).end();++i)
#define equals(a,b) (fabs((a)-(b))<EPS)
#define INF ((1LL<<62)-(1LL<<31))
#define EPS 1e-10
#define PI 3.141592653589793238
#define MOD 1000000007
#define MMOD 998244353
#define MAX 2010101
using namespace std;
using Edge=pair<ll,ll>;
using Graph=vector<vector<int>>;
inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T>inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef long long LL;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
  ll N;
  cin>>N;
  ll A[N-1],B[N-1];
  Graph G(N);
  REP(i,N-1){
    cin>>A[i]>>B[i];
    A[i]--,B[i]--;
    G[A[i]].PB(B[i]);
    G[B[i]].PB(A[i]);
  }
  
  
  ll DISA[N],DISB[N];
  REP(i,N) DISA[i]=INF,DISB[i]=INF;
  DISA[0]=0,DISB[N-1]=0;
  
  bool SEENA[N],SEENB[N];
  REP(i,N) SEENA[i]=false,SEENB[i]=false;
  SEENA[0]=true,SEENB[N-1]=true;
  
  queue<ll> QA,QB;
  QA.push(0),QB.push(N-1);
  
  while(!QA.empty()){
    ll v=QA.front();
    QA.pop();
    FORE(nv,G[v]){
      if(SEENA[nv]) continue;
      SEENA[nv]=true;
      DISA[nv]=DISA[v]+1;
      QA.push(nv);
    }
  }
  
  while(!QB.empty()){
    ll v=QB.front();
    QB.pop();
    FORE(nv,G[v]){
      if(SEENB[nv]) continue;
      SEENB[nv]=true;
      DISB[nv]=DISB[v]+1;
      QB.push(nv);
    }
  }
  
  
  ll ans=0;
  REP(i,N){
    if(DISA[i]<=DISB[i]) ans++;
  }
  
  if(ans>N/2) cout<<"Fennec"<<endl;	// 先攻
  else cout<<"Snuke"<<endl;			// 後攻
  return 0;
}