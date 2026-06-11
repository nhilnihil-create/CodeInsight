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
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<60)
signed main(){
  int K,T; cin>>K>>T;
  int memo=-1;
  priority_queue<pii> Q;
  rep(i,0,T){
    int X; cin>>X;
    Q.push(mp(X,i));
  }
  int ans=0;
  while(Q.size()>0){
    int X=Q.top().first,Y=Q.top().second;
    Q.pop();
    if(Y==memo){
      if(Q.size()==0){
        ans++;
        memo=Y;
        if(X>1) Q.push(mp(X-1,Y));
      }
      else{
        int P=Q.top().first,R=Q.top().second;
        Q.pop();
        memo=R;
        if(P>1) Q.push(mp(P-1,R));
        Q.push(mp(X,Y));
      }
    }
    else{
      memo=Y;
      if(X>1) Q.push(mp(X-1,Y));
    }
  }
  cout<<ans<<endl;
  }

