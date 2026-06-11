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
ll n,m,a[N];
vector<ll> len[N];
int main(){
  cin>>n>>m;
  ll bot=-1;
  for(int i=0;i<n;i++){
      cin>>a[i];
      a[i]--;
      if(i==0)bot=a[0];
      a[i]-=bot;
      if(a[i]<0)a[i]+=m;
      //cout<<a[i]<<" ";
  }
  for(int i=0;i<n-2;i++){
      len[a[i+1]].push_back((a[i+1]-a[i]+m)%m);
  }
  ll base=0,score=0,cnt=1;
  for(int i=0;i<n-1;i++){
      base+=(a[i+1]-a[i]+m)%m;
      if(a[i+1]<a[i]){
	  score+=m-1-a[i]; //cout<<"#"<<i<<" "<<m-1-a[i]<<endl;
	  cnt++;
      }
  }//cout<<base<<" "<<cnt<<endl;
  ll ans=1e17;
  for(ll x=0;x<m;x++){
      chmin(ans,base-score);
      //cout<<score<<" "<<base-score<<endl;
      for(auto l:len[x]){
	  score-=l;
      }
      if(x==0)score--;
      if(x==a[n-1]){
	  score+=-((a[n-1]-a[n-2]+m)%m)+1;
	  cnt--;
      }
      score+=cnt;
  }
  cout<<ans<<endl;
  return 0;
}
