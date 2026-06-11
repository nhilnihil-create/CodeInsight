#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  const int INF=1e9+7;
  int n,m;
  cin>>n>>m;
  std::vector<int> x(n),y(m);
  for(int i=0;i<n;i++)cin>>x[i];
  for(int i=0;i<m;i++)cin>>y[i];
  int xk,yk;
  xk=yk=0;
  for(int i=0;i<n-1;i++){
    int l=x[i+1]-x[i];
    l%=INF;
    l*=i+1;
    l%=INF;
    l*=n-i-1;
    i%=INF;
    xk+=l;
    xk%=INF;
  }
  for(int i=0;i<m-1;i++){
    int l=y[i+1]-y[i];
    l%=INF;
    l*=i+1;
    l%=INF;
    l*=m-i-1;
    i%=INF;
    yk+=l;
    yk%=INF;
  }
  cout<<(xk*yk)%INF<<endl;
}
