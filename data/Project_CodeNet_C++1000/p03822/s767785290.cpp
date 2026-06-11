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
#define FORE(i,a) for(auto &i:a)
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
using namespace std;
using Graph=vector<vector<int>>;
int DP[100010];
Graph G(100010);
bool CAN=true;

int tree(int X){
  if(DP[X]!=0) return DP[X];
  
  vector<int> L;
  REP(i,G[X].size()){
    int a=G[X][i];
    L.push_back(tree(a));
  }
  SORT(L);
  int cnt=0;
  REP(i,L.size()){
    if(cnt<L[i]) cnt=L[i];
    cnt++;
  }
  return DP[X]=cnt;
}

int main(){
  int N;
  cin>>N;
  
  REP(i,N-1){
    int A;
    cin>>A;
    G[A-1].push_back(i+1);
  }
  
  tree(0);
  cout<<DP[0]<<endl;
  return 0;
}