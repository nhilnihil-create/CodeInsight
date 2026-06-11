#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int n;
  cin>>n;
  ll t[n+1]={},a[n+1]={};
  for(int i=0;i<n;i++){
    cin>>t[i];
  }
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  bool conf[n+1];
  for(int i=0;i<n;i++) conf[i]=false;

  ll ht[n+1]={},ha[n+1]={};
  conf[0]=true;
  //conf[n-1]=true;
  ht[0]=t[0];
  //ha[n-1]=a[n-1];

  for(int i=1;i<n;i++){
    if(t[i]>t[i-1]){
      conf[i]=true;
    }
    ht[i]=t[i];
  }

  bool flag=false;
  for(int i=n-1;i>=0;i--){
    ha[i]=a[i];
    if(a[i]>a[i+1]){
      if(conf[i]){
        if(ht[i]!=ha[i]) flag=true;
      }else{
        conf[i]=true;
        if(ha[i]>ht[i]) flag=true;
      }
    }
  }

  if(flag) cout<<0<<endl;
  else{
    ll ans=1;
    for(int i=0;i<n;i++){
      ll mi=min(ha[i],ht[i]);
      ll ma=max(ha[i],ht[i]);
      if(conf[i]) continue;
      ans=ans*(mi)%MOD;
    }
    cout<<ans<<endl;
  }

  return 0;
}
