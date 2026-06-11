#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool used[200005];
ll ans[200005]={0};
int main(){
  ll n,x;
  cin>>n>>x;
  ll m=2*n-1;
  if(x==1||x==m){
    cout<<"No"<<endl;
    return 0;
  }
  for(int i=1;i<=m;i++) used[i]=false;
  if(n==2){
    cout<<"Yes"<<endl;
    for(int i=1;i<=3;i++) cout<<i<<endl;
    return 0;
  }
  if(x==2){
    ans[n]=x;
    ans[n-1]=1;
    ans[n-2]=m-1;
    ans[n+1]=m;
    used[1]=true;
    used[x]=true;
    used[m-1]=true;
    used[m]=true;
  }
  else{
    ans[n]=x;
    ans[n-1]=m;
    ans[n-2]=2;
    ans[n+1]=1;
    used[x]=true;
    used[m]=true;
    used[1]=true;
    used[2]=true;
  }
  ll ps=1;
  for(int i=1;i<=m;i++){
    if(ans[i]>0) continue;
    while(used[ps]) ps++;
    ans[i]=ps;
    used[ps]=true;
  }
  cout<<"Yes"<<endl;
  for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
}
