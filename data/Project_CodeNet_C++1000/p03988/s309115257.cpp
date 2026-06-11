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
  bool CAN=true;
  vector<int> L;
  REP(i,N){
    int a; cin>>a;
    L.push_back(a);
  }
  
  SORT(L);
  int DIM[L.at(N-1)+1];
  REP(i,L.at(N-1)+1) DIM[i]=0;
  for(int i=0; i<L.size(); ++i) DIM[L.at(i)]++;
  
  if(L.at(N-1)%2==0){
    if(L.at(N-1)!=2*L.at(0)) CAN=false;
    for(int i=L.at(0)+1; i<=L.at(N-1); ++i){
      if(DIM[i]<2) CAN=false;
    }
    if(DIM[L.at(0)]!=1) CAN=false;
  }
  else{
    if(L.at(N-1)!=2*L.at(0)-1) CAN=false;
    for(int i=L.at(0); i<=L.at(N-1); ++i){
      if(DIM[i]<2) CAN=false;
    }
    if(DIM[L.at(0)]!=2) CAN=false;
  }
  
  if(CAN) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
  return 0;
}