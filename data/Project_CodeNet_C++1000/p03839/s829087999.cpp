#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <time.h>
#define ll long long
#define double long double
#define itn int
#define endl '\n'
#define co(ans) cout<<ans<<endl
#define COYE cout<<"YES"<<endl
#define COYe cout<<"Yes"<<endl
#define COye cout<<"yes"<<endl
#define CONO cout<<"NO"<<endl
#define CONo cout<<"No"<<endl
#define COno cout<<"no"<<endl
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,1,n)
#define ALL(V) (V).begin(),(V).end()
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define INF ((1LL<<62)-(1LL<<31))
#define EPS 1e-10
#define PI 3.141592653589793238
#define MOD 1000000007
#define MAX 5100000
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
bool CAN=true;
using namespace std;

int main(){
  ll N,K,ans=0;
  cin>>N>>K;
  
  ll A[N+1],SUM[N+2],BLACK[N+2];
  SUM[0]=0; //累積和
  BLACK[0]=0; //累積和(A[i]>0のみ)
  for(int i=1; i<=N; ++i){
    cin>>A[i];
    SUM[i]=SUM[i-1]+A[i];
    BLACK[i]=BLACK[i-1];
    if(A[i]>0) BLACK[i]+=A[i];
  }
  SUM[N+1]=SUM[N];
  BLACK[N+1]=BLACK[N];
  
  for(int i=1; i<=N-K+1; ++i){
    ll cnt=0;
    
    cnt+=BLACK[i-1];
    cnt+=BLACK[N]-BLACK[i+K-1];
    cnt+=max(SUM[i+K-1]-SUM[i-1],0ll);
    
    chmax(ans,cnt);
  }
  
  cout<<ans<<endl;
  return 0;
}