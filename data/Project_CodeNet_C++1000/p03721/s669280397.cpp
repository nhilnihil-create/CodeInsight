#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t m,k,z=0,j;
  cin>>m>>k;
  vector<pair<int,int>> x(m);
  for(j=0;j<m;j++) cin>>x.at(j).first>>x.at(j).second;
  sort(x.begin(),x.end());
  for(auto y:x){
    z+=y.second;
    if(z>=k){
      cout<<y.first<<endl;
      break;
    }
  }
}