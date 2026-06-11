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

////////// BIT (binary indexed tree) //////////

//1-indexed
class BIT{
public:
  ll n;
  vector<ll> bit;
  BIT(ll n):n(n),bit(n+1,0){}
  
  void add(ll i,ll x){
    if(i==0) return;
    for(ll k=i;k<=n;k+=(k & -k)) bit[k]+=x;
  }
  
  ll sum(ll i){
    ll s=0;
    if(i==0) return s;
    for(ll k=i;k>0;k-=(k & -k)) s+=bit[k];
    return s;
  }
  
  //a_1 + a_2 + … + a_i >= x となるような最小のiを求める(a_k >= 0)
  //xが0以下の場合は該当するものなし→0を返す
  ll lower_bound(ll x){
    if(x<=0) return 0;
    else{
      ll i=0,r=1;
      //最大としてありうる区間の長さを取得する
      //n以下の最小の二乗のべき(BITで管理する数列の区間で最大のもの)を求める
      while(r<n) r=r<<1;
      //区間の長さは調べるごとに半分になる
      for(int len=r;len>0;len=len>>1){
        //その区間を採用する場合
        if(i+len<n && bit[i+len]<x){
          x-=bit[i+len];
          i+=len;
        }
      }
      return i+1;
    }
  }
};

//////////////////////////////////////////////////

int main(){
  ll N,K;
  cin>>N>>K;
  ll A[N+1];
  RREP(i,N) cin>>A[i];
  
  ll S[N+1]={};
  RREP(i,N) S[i]=S[i-1]+A[i]-K;
  
  // i<j S[i]<=S[j] を満たす(i,j)の数を求める
  vector<pair<ll,ll>> L;
  REP(i,N+1) L.PB(MP(S[i],i));
  SORT(L);
  
  ll ans=0;
  BIT U(N);
  REP(i,N+1){
    ans+=N-L[i].second-(U.sum(N)-U.sum(L[i].second));
    U.add(L[i].second,1);
  }
  
  co(ans);
  return 0;
}