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
  ll N,X;
  cin>>N>>X;
  
  ll A[2*N+1],ANS[N+1];
  ANS[0]=0LL;
  for(int i=1; i<=N; ++i){
    cin>>A[i];
    A[N+i]=A[i];
    ANS[i]=i*X;
  }
  
  ll DP[N+1][N+1];
  // DP[i][j] 魔法をj回唱えるとき、スライムiを捕まえるのにかかる最短時間
  
  REP(i,N+1){
    REP(j,N+1){
      DP[i][j]=0LL;
      if(j==0 && i>0) DP[i][j]=A[i];
    }
  }
  
  for(int i=1; i<=N; ++i){
    for(int j=1; j<=N-1; ++j){
      DP[i][j]=min(DP[i][j-1],A[i+N-j]);
    }
  }
  
  for(int i=1; i<=N; ++i){
    for(int j=0; j<=N-1; ++j){
      ANS[j]+=DP[i][j];
    }
  }
  
  cout<<*min_element(ANS+0,ANS+N)<<endl;
  return 0;
}