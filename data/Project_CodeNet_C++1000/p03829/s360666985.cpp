#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t m,b,c,j,ans=0;
  cin>>m>>b>>c;
  vector<int64_t> x(m);
  for(j=0;j<m;j++) cin>>x.at(j);
  for(j=1;j<m;j++) ans+=min(b*(x.at(j)-x.at(j-1)),c);
  cout<<ans<<endl;
}