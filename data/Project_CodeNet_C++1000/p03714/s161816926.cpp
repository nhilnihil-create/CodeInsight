#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#define MOD 1000000007
#define inf (1<<30)
typedef long long ll;
using namespace std;

int main(){
  priority_queue<ll,vector<ll>,greater<ll>> P;
  priority_queue<ll> Q;
  int n;
  cin>>n;
  ll sum1=0,sum2=0;
  ll a[3*n+1]={};
  for(int i=1;i<=n;i++){
    cin>>a[i];
    sum1+=a[i];
    P.push(a[i]);
  }
  for(int i=n+1;i<=2*n;i++){
    cin>>a[i];
  }
  for(int i=2*n+1;i<=3*n;i++){
    cin>>a[i];
    sum2+=a[i];
    Q.push(a[i]);
  }
  ll l[2*n+1]={};
  ll r[2*n+1]={};
  l[n]=sum1;
  r[2*n]=sum2;
  for(int i=n+1;i<=2*n;i++){
    ll u=P.top();
    if(u<a[i]){
      l[i]=l[i-1]+a[i]-u;
      P.pop();
      P.push(a[i]);
    }else{
      l[i]=l[i-1];
    }
  }
  for(int i=2*n-1;i>=n;i--){
    ll v=Q.top();
    if(v>a[i+1]){
      r[i]=r[i+1]+a[i+1]-v;
      Q.pop();
      Q.push(a[i+1]);
    }else{
      r[i]=r[i+1];
    }
  }
  ll ans=l[n]-r[n];
  for(int i=n;i<=2*n;i++){
    ans=max(ans,l[i]-r[i]);
    //cout<<l[i]<<" "<<r[i]<<endl;
  }
  cout<<ans<<endl;
  return 0;
}
