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
  int W,H; cin>>W>>H;
  vector<pii> A(W+H);
  rep(i,0,W){
    cin>>A[i].first;
    A[i].second=0;
  }
  rep(i,W,H+W){
    cin>>A[i].first;
    A[i].second=1;
  }
  sort(ALL(A));
  vi B(2);
  B[0]=W+1;
  B[1]=H+1;
  int ans=0;
  rep(i,0,H+W){
    ans+=B[A[i].second^1]*A[i].first;
    B[A[i].second]--;
  }
  cout<<ans<<endl;
  }

