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

const int DAT_SIZE=(1<<18)-1;

ll data[DAT_SIZE],datb[DAT_SIZE];

void add(int a,int b,int x,int k,int l,int r){
  if(a<=l&&r<=b){
    data[k]+=x;
  }
  else if(l<b&&a<r){
    datb[k]+=(min(b,r)-max(a,l))*x;
    add(a,b,x,k*2+1,l,(l+r)/2);
    add(a,b,x,k*2+2,(l+r)/2,r);
  }
}

//[a,b),[l,r)
ll sum(int a,int b,int k,int l,int r){
  if(b<=l||r<=a){
    return 0;
  }
  else if(a<=l&&r<=b){
    return data[k]*(r-l)+datb[k];
  }
  else{
    ll res=(min(b,r)-max(a,l))*data[k];
    res+=sum(a,b,k*2+1,l,(l+r)/2);
    res+=sum(a,b,k*2+2,(l+r)/2,r);
    return res;
  }
}


int main(){
  int n,m;
  cin>>n>>m;
  std::vector<int> v[m+1];
  int a[n+1]={};
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(i>0) v[a[i]].push_back(a[i-1]);
  }

  ll ans=0;
  for(int i=1;i<n;i++){
    if((a[i]-a[i-1]+m)%m==1) ans++;
    else{
      if(a[i-1]<a[i]) add(a[i-1]+2,a[i]+1,1,0,0,m+1);
      else{
        if(a[i-1]+2<=m) add(a[i-1]+2,m+1,1,0,0,m+1);
        if(a[i-1]!=m) add(1,a[i]+1,1,0,0,m+1);
        else add(2,a[i]+1,1,0,0,m+1);
      }
    }
  }

  /*for(int i=1;i<=m;i++){
    cout<<sum(i,i+1,0,0,m+1)<<endl;
  }*/

  ll tmp=0;
  for(int i=1;i<n;i++){
    if((a[i]-a[i-1]+m)%m==1) continue;
    tmp+=min((a[i]-a[i-1]+m)%m,a[i]);
  }

  ll res=tmp;
  for(int i=2;i<=m;i++){
    ll minus=sum(i,i+1,0,0,m+1);
    ll plus=0;
    int two=i-1;
    for(int j=0;j<v[two].size();j++){
      if((two-v[two][j]+m)%m==1) continue;
      plus+=(two-v[two][j]+m)%m-1;
    }
    tmp=tmp+plus-minus;
    //cout<<i<<" "<<plus<<" "<<minus<<" "<<tmp<<endl;
    res=min(res,tmp);
  }
  ans=ans+res;
  cout<<ans<<endl;

  return 0;
}
