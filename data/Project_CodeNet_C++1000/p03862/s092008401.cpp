#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N,x;
  cin>>N>>x;
  vector<int>a(N);
  for(int i=0;i<N;i++)cin>>a[i];
  ll ans=0;
  for(int i=0;i<N;i++)if(a[i]>x){
    ans+=a[i]-x;
    a[i]=x;
  }
  for(int i=0;i<N-1;i++){
    if(a[i]+a[i+1]>x){
      int d=a[i+1]+a[i]-x;
      if(d<=0)continue;
      if(d>a[i+1])ans+=a[i+1],a[i+1]=0;
      else ans+=d,a[i+1]-=d;
    }
  }
  for(int i=N-1;i>=1;i--){
    if(a[i]+a[i-1]>x){
      int d=a[i]+a[i-1]-x;
      if(d<=0)continue;
      if(d>a[i-1])ans+=a[i-1],a[i-1]=0;
      else ans+=d,a[i-1]-=d;
    }
  }
  cout<<ans<<endl;
  return 0;
}
