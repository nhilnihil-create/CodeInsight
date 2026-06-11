#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod;
#define mul(a,b) a=a*b%mod;
#define N 200010
ll dp[N],dq[N];
ll n,m,a[N];
ll res[N];
int main(){
  for(int i=0;i<N;i++)dp[i]=dq[i]=0;
  cin>>n>>m;
  ll sum=0;
  for(int i=0;i<n;i++){
      cin>>a[i]; a[i]--;
      if(i){
          ll b=a[i]; if(b<a[i-1])b+=m;
          sum+=b-a[i-1];
          dp[a[i-1]]++;
          dp[b]--;
          dq[a[i-1]]-=a[i-1]+1;
          dq[b]+=a[i-1]+1;
      }
  }
  for(int i=0;i<m;i++)res[i]=0;
  ll p=0,q=0;
  for(ll i=0;i<N;i++){
      res[i%m]+=p*i+q;
      p+=dp[i],q+=dq[i];
  }
  ll ans=0;
  for(int i=0;i<m;i++)chmax(ans,res[i]);
  cout<<sum-ans<<endl;
  return 0;
}

