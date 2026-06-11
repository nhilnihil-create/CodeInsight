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
  string S;
  cin>>S;
  int N=S.size();
  bool flag=1;
  rep(i,1,N){
    if(S[i]==S[i-1]){
      flag=0;
      cout<<i<<" "<<i+1<<endl;
      break;
    }
  }
  if(flag){
    rep(i,2,N){
      if(S[i]==S[i-2]){
        flag=0;
        cout<<i-1<<" "<<i+1<<endl;
        break;
      }
    }
  }
  if(flag)
    cout<<-1<<" "<<-1<<endl;
  }

