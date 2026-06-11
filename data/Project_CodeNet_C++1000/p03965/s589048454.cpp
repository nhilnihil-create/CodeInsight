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
  int count=0;
  int K=N/2;
  bool flag=1;
  int ans=0;
  rep(i,0,N){
    if(flag){
      if(S[i]=='g'){
        count++;
        if(count==N-K)
          flag=0;
      }
    }
    else{
      if(S[i]=='g')
        ans++;
    }
  }
  cout<<ans<<endl;
  }

