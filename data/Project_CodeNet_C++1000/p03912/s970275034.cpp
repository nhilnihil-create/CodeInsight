#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,i,j,k,ans=0;
  cin>>n>>m;
  int x[n],y[m];
  memset(y,0,sizeof(y));
  map<int,int> mi;
  for(i=0;i<n;i++){
    cin>>x[i];
    mi[x[i]]++;
    y[x[i]%m]++;
  }
  ans+=y[0]/2;
  y[0]%=2;
  if(m%2==0){
    ans+=y[m/2]/2;
    y[m/2]%=2;
  }
  for(i=1;i<m;i++){
    if(i*2==m) continue;
    k=min(y[i],y[m-i]);
    ans+=k;
    y[i]-=k;
    y[m-i]-=k;
    //cout << i << ":" << k << ":" << ans << endl;
  }
  for(i=0;i<n;i++) {
    k=min(y[x[i]%m],mi[x[i]])/2;
    if(k>0){
      ans+=k;
      y[x[i]%m]-=k*2;
      mi[x[i]]-=k*2;
    }
  }
  cout << ans << endl;
  return 0;
}
