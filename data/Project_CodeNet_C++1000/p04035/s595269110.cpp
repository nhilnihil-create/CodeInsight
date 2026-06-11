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
  int N,L; cin>>N>>L;
  vi A(N);
  rep(i,0,N) cin>>A[i];
  int sum=0,memo=1;
  rep(i,1,N){
    if(sum<A[i]+A[i-1]){
      sum=A[i]+A[i-1];
      memo=i;
    }
  }
  if(sum>=L){
    cout<<"Possible"<<endl;
    rep(i,1,memo) cout<<i<<endl;
    rep(i,1,N-memo) cout<<N-i<<endl;
    cout<<memo<<endl;
  }
  else cout<<"Impossible"<<endl;
  }
