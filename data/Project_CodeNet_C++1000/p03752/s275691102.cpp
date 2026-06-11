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
  ll N,K,ans=INF;
  cin>>N>>K;
  
  ll A[N],DIV[N],t=0;
  REP(i,N) cin>>A[i];
  
  for(int bit=0; bit<(1<<N); ++bit){
    vector<int> S;
    for(int i=0; i<N; ++i){
      DIV[i]=0;
      if(bit&(1<<i)){
        S.push_back(A[i]);
        DIV[i]=1;
        if(S.size()==1) t=i;
      }
    }
    
    if(S.size()==K){
      ll cnt=0,mx=A[0];
      
      for(int i=1; i<N; ++i){
        if(DIV[i]==1){
          if(mx>=A[i]){
            cnt+=mx-A[i]+1;
            mx+=1;
          }
          else mx=A[i];
        }
        chmax(mx,A[i]);
      }
      chmin(ans,cnt);
    }
  }
  
  cout<<ans<<endl;
  return 0;
}