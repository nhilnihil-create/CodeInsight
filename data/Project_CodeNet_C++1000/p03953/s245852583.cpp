#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
  int n;cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  for(int i=n-1;i;i--)v[i]-=v[i-1];
  int m,k;cin>>m>>k;
  vector<int> a(m);
  for(int &p:a){cin>>p;p--;}
  vector<int> b(n);
  for(int i=0;i<n;i++)b[i]=i;
  for(int i=0;i<m;i++)swap(b[a[i]],b[a[i]+1]);
  while(k){
    if(k&1){
      vector<int>tmp(n);
      for(int i=0;i<n;i++)tmp[i]=v[b[i]];
      for(int i=0;i<n;i++)v[i]=tmp[i];
    }
    k>>=1;
    vector<int> tmp(n);
    for(int i=0;i<n;i++)tmp[i]=b[b[i]];
    for(int i=0;i<n;i++)b[i]=tmp[i];
  }
  cout<<v[0]<<endl;
  for(int i=1;i<n;i++){
    v[i]+=v[i-1];
    cout<<v[i]<<endl;
  }
}
