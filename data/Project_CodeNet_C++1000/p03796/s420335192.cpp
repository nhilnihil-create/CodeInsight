#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t m,i,z=1,mod=1e9+7;
  cin>>m;
  for(i=1;i<=m;i++) z=z*i%mod;
  cout<<z<<endl;
}