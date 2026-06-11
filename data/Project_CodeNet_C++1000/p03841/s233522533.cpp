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
  int N; cin>>N;
  vector<pii> A(N);
  set<int> S;
  rep(i,0,N){
    cin>>A[i].first;
    A[i].second=i+1;
    S.insert(A[i].first-1);
  }
  int memo=0;
  sort(ALL(A));
  vi ans(N*N);
  rep(i,0,N){
    rep(j,0,A[i].second-1){
      while(S.count(memo)) memo++;
      ans[memo]=A[i].second;
      if(memo>=A[i].first-1){
        cout<<"No"<<endl;
        return 0;
      }
      memo++;
    }
  }
  memo=N*N-1;
  reverse(ALL(A));
  rep(i,0,N){
    rep(j,0,N-A[i].second){
      while(S.count(memo)) memo--;
      ans[memo]=A[i].second;
      if(memo<=A[i].first-1){
        cout<<"No"<<endl;
        return 0;
      }
      memo--;
    }
  }
  cout<<"Yes"<<endl;
  rep(i,0,N) ans[A[i].first-1]=A[i].second;
  rep(i,0,N*N) cout<<ans[i]<<" ";
  cout<<endl;
  }

