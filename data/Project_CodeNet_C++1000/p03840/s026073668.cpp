#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int I,O,T,J,L,S,Z;
  cin>>I>>O>>T>>J>>L>>S>>Z;
  int ans=I/2*2+J/2*2+L/2*2+O;
  if(I!=0 && J!=0 && L!=0)
    cout<<max((I-1)/2*2+(J-1)/2*2+(L-1)/2*2+3+O,ans)<<endl;
  else
    cout<<ans<<endl;
}