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
  vi A(N);
  rep(i,0,N) cin>>A[i];
  vector<map<int,int>> M(2);
  rep(i,0,N) M[i%2][A[i]]++;
  sort(ALL(A));
  int ans=0;
  rep(i,0,N){
    if(M[i%2][A[i]]>0){
      M[i%2][A[i]]--;
    }
    else{
      ans++;
      M[1-i%2][A[i]]--;
    }
  }
  cout<<ans/2<<endl;
  }

