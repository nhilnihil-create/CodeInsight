#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<set>
#include<map>
#include<queue>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);++i)
#define rrep(i,n) for(int (i)=(n)-1;(i)>=0;--i)
#define rep1(i,n) for(int (i)=1;(i)<=(n);++i)
#define rrep1(i,n) for(int (i)=(n);(i)>=1;--i)
#define pb push_back
#define fr first
#define sc second
typedef long long ll;
typedef pair<int,int> P;
typedef pair<long long,long long> LP;
typedef double db;
using namespace std;
ll N,A[300000];
priority_queue<ll> p,q;//でかい方から
ll ans1[300000];
ll ans2[300000];

int main(){
  cin>>N;
  rep(i,3*N) cin>>A[i];
  ll sum1=0,sum2=0;
  rep(i,N){
    q.push(-A[i]);
    sum1+=A[i];
  }
  ans1[N] = sum1;
  for(ll i=N+1;i<2*N+1;i++){// [0,i) [i,3*N)
    ll x = -q.top();
    if(x < A[i-1]){
      sum1 -= x;
      sum1 += A[i-1];
      q.pop();
      q.push(-A[i-1]);
    }
    ans1[i]=sum1;
  }
  rrep(i,N){
    p.push(A[2*N+i]);
    sum2+=A[2*N+i];
  }
  ans2[2*N]=sum2;
  for(ll i=2*N-1; i>=N; i--){
    ll x = p.top();
    if( x > A[i] ){
      sum2 -= x;
      sum2 += A[i];
      p.pop();
      p.push(A[i]);
    }
    ans2[i]=sum2;
  }
  ll ans = -0xfffffffffffffff;
  rep(i,N+1){
    ans = max(ans,ans1[i+N]-ans2[i+N]);
    // cout<<i<<" "<<ans1[i+N]<<" "<<ans2[i+N]<<endl;
  }
  cout<<ans<<endl;
}
