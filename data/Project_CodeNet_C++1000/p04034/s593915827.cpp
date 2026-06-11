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
#define co(ans) cout<<ans<<endl;
#define COYE cout<<"YES"<<endl;
#define COYe cout<<"Yes"<<endl;
#define COye cout<<"yes"<<endl;
#define CONO cout<<"NO"<<endl;
#define CONo cout<<"No"<<endl;
#define COno cout<<"no"<<endl;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,1,n)
#define ALL(V) ((V).begin(),(V).end())
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define INF ((1LL<<62)-(1LL<<31))
#define EPS 1e-10
#define PI 3.141592653589793238
#define MOD 1000000007
#define MAX 5100000
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
const int vx[4]={0,1,0,-1},vy[4]={1,0,-1,0};
using namespace std;

int main(){
  int N,M,ans=0;
  cin>>N>>M;
  int X[M],Y[M],CNT[N];
  REP(i,M) cin>>X[i]>>Y[i];
  REP(i,N) CNT[i]=1;
  
  bool CAN[N];
  REP(i,N) CAN[i]=false;
  CAN[0]=true;
  
  REP(i,M){
    if(CAN[X[i]-1]==true){
      CAN[Y[i]-1]=true;
      if(CNT[X[i]-1]==1) CAN[X[i]-1]=false;
    }
    CNT[X[i]-1]--;
    CNT[Y[i]-1]++;
  }
  
  REP(i,N){
    if(CAN[i]==true) ans++;
  }
  
  cout<<ans<<endl;
  return 0;
}