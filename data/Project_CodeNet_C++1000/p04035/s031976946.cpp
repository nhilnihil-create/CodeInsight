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
using namespace std;

int main(){
  ll N,L,t=1;
  cin>>N>>L;
  ll A[N];
  REP(i,N) cin>>A[i];
  
  bool CAN=false;
  REP(i,N-1){
    if(A[i]+A[i+1]>=L){
      CAN=true;
      t=i+1;
    }
  }
  
  if(CAN){
    cout<<"Possible"<<endl;
    for(int i=1; i<=N-2; ++i){
      if(i<=t-1) cout<<i<<endl;
      else cout<<N+t-1-i<<endl;
    }
    cout<<t<<endl;
  }
  else cout<<"Impossible"<<endl;
  return 0;
}