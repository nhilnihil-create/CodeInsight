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
  int H,W; cin>>H>>W;
  map<char,char> M;
  rep(i,0,H){
    string S; cin>>S;
    rep(j,0,W) M[S[j]]++;
  }
  int sum1=0,sum2=0;
  for(auto p:M){
    int X=p.second;
    if(X%4==0) continue;
    else if(X%2==0) sum1++;
    else{
      sum2++;
      X--;
      //if(X%4==2) sum1++;
    }
  }
  int max1=0,max2=0;
  if(H%2==1) max1+=W/2;
  if(W%2==1) max1+=H/2;
  if(H%2==1&&W%2==1) max2++;
  string ans="No";
  if(max2>=sum2&&max1>=sum1) ans="Yes";
  cout<<ans<<endl;
  }
