#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,x,i,ans=0;
  map<int,int> m;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>x;
    if(m.count(x)) m.at(x)++;
    else m[x]=1;
  }
  for(auto z:m) if(z.second%2==1) ans++;
  cout<<ans<<endl;
}