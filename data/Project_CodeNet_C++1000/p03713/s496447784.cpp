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
signed main(){
  int H,W; cin>>H>>W;
  int ans=MOD;
  vi P={H/3,H/3+1,W/3,W/3+1};
  rep(i,0,2){
    int K=H-P[i];
    int Q=K/2,R=W/2;
    int S1=P[i]*W,S2=Q*W,S3=(K-Q)*W;
    ans=min(ans,max(S1,max(S2,S3))-min(S1,min(S2,S3)));
    S1=P[i]*W;
    S2=R*K;
    S3=(W-R)*K;
    ans=min(ans,max(S1,max(S2,S3))-min(S1,min(S2,S3)));
   // cout<<P[i]<<" "<<Q<<" "<<R<<endl;
  }
  rep(i,2,4){
    int K=W-P[i];
    int Q=K/2,R=H/2;
    int S1=P[i]*H,S2=Q*H,S3=(K-Q)*H;
    ans=min(ans,max(S1,max(S2,S3))-min(S1,min(S2,S3)));
    S1=P[i]*H;
    S2=R*K;
    S3=(H-R)*K;
    ans=min(ans,max(S1,max(S2,S3))-min(S1,min(S2,S3)));
   //cout<<P[i]<<" "<<Q<<" "<<R<<endl;
  }
  cout<<ans<<endl;
  }
