#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
signed main(){
  int N; cin>>N;
  string S1,S2; cin>>S1>>S2;
  int ans=3;
  int k=1;
  bool flag=1;
  if(S1[0]==S1[1]){
    ans*=2;
    k++;
    flag=0;
  }
  rep(i,k,N){
    if(S1[i]==S1[i+1]){
      i++;
      if(flag)
        ans*=2;
      else
        ans*=3;
      ans%=MOD;
      flag=0;
    }
    else{
      if(flag){
        ans*=2;
        ans%=MOD;
      }
      flag=1;
    }
  }
  cout<<ans<<endl;
  }

