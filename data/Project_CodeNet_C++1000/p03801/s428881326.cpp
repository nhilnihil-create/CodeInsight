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
#define N 100010
ll n,a[N];
vector<ll> e,v;
ll ans[N];
int main(){
  cin>>n;
  ll ma=0;
  a[0]=0; v.push_back(0); e.push_back(0);
  for(int i=1;i<=n;i++){
      cin>>a[i];
      v.push_back(a[i]);
      if(ma<a[i]){
	  ma=a[i];
	  e.push_back(i);
      }
      ans[i]=0;
  }
  sort(v.begin(),v.end());
  reverse(e.begin(),e.end());
  ll cnt=0;
  for(int i=0;i<e.size()-1;i++){
      ans[e[i]]+=cnt*(a[e[i]]-a[e[i+1]]);
      while(v.size()>0&&v.back()>=a[e[i+1]]){
	  cnt++;
	  ans[e[i]]+=v.back()-a[e[i+1]];
	  v.pop_back();
      }
  }
  for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
  return 0;
}
