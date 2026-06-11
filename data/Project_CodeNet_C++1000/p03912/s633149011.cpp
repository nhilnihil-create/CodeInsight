#include <bits/stdc++.h>
using namespace std;
#define int long long
bool used[100001]={};
vector<int> hen[100001];
int grundy(int a){
  used[a]=true;
  int ans=0;
  for(int i=0;i<hen[a].size();i++){
    if(!used[hen[a][i]])ans^=(1+grundy(hen[a][i]));
  }
  return ans;
}
signed main() {
int n,m;
cin>>n>>m;
int x[n];
for(int i=0;i<n;i++)cin>>x[i];
sort(x,x+n);
int a[m]={},b[m]={},c=1;
for(int i=1;i<n;i++){
  if(x[i-1]!=x[i]){
    a[x[i-1]%m]+=c;
    b[x[i-1]%m]+=c%2;
    c=1;
  }else c++;
}
a[x[n-1]%m]+=c;
b[x[n-1]%m]+=c%2;
int ans=a[0]/2;
if(m%2==0)ans+=a[m/2]/2;
for(int i=1;i<(m+1)/2;i++){
  //cerr<<a[i]<<' '<<a[m-i]<<endl;
  if(a[i]<a[m-i]){
    swap(a[i],a[m-i]);
    swap(b[i],b[m-i]);
  }
  ans+=a[m-i]+(a[i]-max(b[i],a[m-i]))/2;
  
}
cout<<ans<<endl;

return 0;
}
