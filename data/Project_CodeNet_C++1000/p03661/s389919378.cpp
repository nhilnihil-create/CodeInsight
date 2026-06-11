#include <bits/stdc++.h>
using namespace std;
signed main(){
  long long n,d[1000000],a=2000000001,b;
  cin>>n;
  d[0]=0;
  for(int i=1;i<=n;i++){
    cin>>d[i];
    d[i]+=d[i-1];
  }

  for(int i=1;i<n;i++){
    b=d[i]*2-d[n];
    if(b<0)
      b*=-1;
    if(a>b)
      a=b;
  }
  cout<<a<<endl;
    
  return(0);
}
