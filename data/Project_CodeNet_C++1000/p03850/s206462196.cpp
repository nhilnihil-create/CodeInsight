#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int N;
vector<ll> A;
vector<char> opt;

ll sum[100010];
int nxt[100010];
ll rsum[100010];

void chmax(ll &a,ll b){
    if(a<b) a=b;
}

int main(){
  cin>>N;
  A.resize(N);
  opt.resize(N);
  cin>>A[0];
  opt[0]='+';
  for(int i=1;i<N;i++){
      cin>>opt[i];
      cin>>A[i];
  }

  for(int i=0;i<=N;i++) nxt[i]=N;
  for(int i=N-1;i>=0;i--){
      nxt[i]=nxt[i+1];
      if(opt[i]=='-') nxt[i]=i;
  }

  for(int i=0;i<N;i++){
      if(i>0) sum[i]=sum[i-1];
      if(opt[i]=='+') sum[i]+=A[i];
      else sum[i]-=A[i];
  }

  for(int i=N-1;i>=0;i--){
      rsum[i]=rsum[i+1];
      rsum[i]+=A[i];
  }

  ll ans=sum[N-1];
  for(int i=0;i<N;i++){
      if(opt[i]=='+') continue;
      ll res=sum[i-1]+rsum[nxt[i+1]];
      ll minus=abs(rsum[i]-rsum[nxt[i+1]]);
      res-=minus;
      ans=max(ans,res);
  }

  cout<<ans<<endl;


  return 0;
}
