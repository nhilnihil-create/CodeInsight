#include"bits/stdc++.h"
using namespace std;

#define int long long

pair<int,int> arr[200005];
int ind[200005],n,k,nex=1;

int ft[200005];
inline int ls(int x){
  return x&(-x);
}
void update(int p,int v=1){
  for(;p<=200000;p+=ls(p))ft[p]++;
}
int query(int p){
  int ans=0;
  for(;p;p-=ls(p))ans+=ft[p];
  return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    int ans=0;
    arr[0]=make_pair(0,0);
    for(int x=1;x<=n;x++){
      cin>>arr[x].first;
      arr[x].first-=k;
      arr[x].second=x;
      if(x>0){
        arr[x].first+=arr[x-1].first;
      }
    }
    sort(arr,arr+n+1);
    for(int x=0;x<=n;x++){
      if(x>0 && arr[x].first!=arr[x-1].first)nex++;
      ind[arr[x].second]=nex;
    }
    for(int x=0;x<=n;x++){
      ans+=query(ind[x]);
      update(ind[x]);
    }
    cout<<ans;
    return 0;
}
