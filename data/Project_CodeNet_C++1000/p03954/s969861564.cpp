#include <bits/stdc++.h>
using namespace std;

int n,N;

bool TOP(vector<int> &w){
  if(w[n-2]+w[n-1]+w[n]==3)return 1;
  if(w[n-2]+w[n-1]+w[n]==2){
    if(w[n-1])return 1;
    for(int i=0;i<n-1;i++){
      int l=w[n-2-i],r=w[n+i];
      if(i&1){if(l||r)return 1;}
      else if(!(l&&r))return 0;
    }
    return !(n&1);
  }
  if(w[n-2]+w[n-1]+w[n]==1){
    if(!w[n-1])return 0;
    for(int i=0;i<n-1;i++){
      int l=w[n-2-i],r=w[n+i];
      if(i&1){if(!(l&&r))return 0;}
      else if(l||r)return 1;
    }
    return n&1;
  }
  return 0;
}

signed main(){
  cin>>n;N=2*n-1;
  vector<int> v(N),w(N);
  for(int i=0;i<N;i++)cin>>v[i];
  int l=0,r=N+1;//rが答え
  while(r-l>1){
    int mid=(r+l)>>1;
    for(int i=0;i<N;i++)w[i]=(v[i]<=mid);
    (TOP(w)?r:l)=mid;
  }
  cout<<r<<endl;
}
