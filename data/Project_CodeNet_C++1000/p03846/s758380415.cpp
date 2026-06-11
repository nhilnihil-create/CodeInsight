#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<cmath>
#include<bitset>
#include<queue>
#define ll long long
#define itn int
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
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define INF ((1LL<<62)-(1LL<<31))
#define MOD 1000000007
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;


int main(){
  int N;
  cin>>N;
  int B[N];
  REP(i,N) B[i]=0;
  int A[N];
  REP(i,N){
    cin>>A[i];
    B[A[i]]++;
  }
  
  bool CAN=true;
  
  if(N%2==1){
    for(int i=0; i<=N/2; ++i){
      if((B[0]!=1)||(B[2*i]!=2&&i>0)) CAN=false;
    }
  }
  else{
    for(int i=0; i<N/2; ++i){
      if(B[2*i+1]!=2) CAN=false;
    }
  }
  
  if(CAN){
    ll A=1;
    for(int i=1; i<=N/2; ++i){
      A=A*2%MOD;
    }
    cout<<A<<endl;
  }
  else cout<<0<<endl;
}