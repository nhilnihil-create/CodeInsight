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
  int N;
  cin>>N;
  vector<pair<int,int>> X;
  int A[N*N+1];
  REP(i,N*N+1) A[i]=0;
  REP(i,N){
    int a;
    cin>>a;
    X.push_back(make_pair(a,i+1));
    A[a]=i+1;
  }
  
  SORT(X);
  for(int i=0; i<N; ++i){
    if(X[i].second==1){
      if(i==N-1) break;
      ++i;
    }
    int S=X[i].second;	//現在書き換える数字
    int Snum=S-1;		//現在書き換える数字があと何回使えるか
    for(int j=1; j<=N*N; ++j){
      if(A[j]==S) CAN=false;
      else if(A[j]==0){
        A[j]=S;
        Snum--;
      }
      if(Snum==0) break;
    }
  }
  
  for(int i=N-1; i>=0; --i){
    if(X[i].second==N){
      if(i==0) break;
      --i;
    }
    int S=X[i].second;	//現在書き換える数字
    int Snum=N-S;		//現在書き換える数字があと何回使えるか
    for(int j=N*N; j>=1; --j){
      if(A[j]==S) CAN=false;
      else if(A[j]==0){
        A[j]=S;
        Snum--;
      }
      if(Snum==0) break;
    }
  }
  
  if(CAN){
    COYe;
    RREP(i,N*N) cout<<A[i]<<" ";
    cout<<endl;
  }
  else CONo;
  return 0;
}