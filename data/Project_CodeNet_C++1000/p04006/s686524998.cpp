#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long LINF=1e18;
template<typename T>
void chmin(T &a,T b){
  if(a>b)a=b;
}

signed main(){
  int n,x;cin>>n>>x;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  vector<int> w(n);
  for(int i=0;i<n;i++)w[i]=v[i];
  int ans=LINF;
  for(int k=0;k<n;k++){
    int tmp=k*x;
    for(int i=0;i<n;i++)tmp+=w[i];
    chmin(ans,tmp);
    for(int i=0;i<n;i++)chmin(w[(i+k+1)%n],v[i]);
  }
  cout<<ans<<endl;
}
