#include<bits/stdc++.h>
using namespace std;
int main(){
  int m,j,x=0;
  cin>>m;
  vector<int> v(m);
  for(j=0;j<m;j++){
    cin>>v.at(j);
    x+=v.at(j);
  }
  if(x%10>0) cout<<x<<endl;
  else{
    sort(v.begin(),v.end());
    for(j=0;j<m;j++){
      if(v.at(j)%10>0){
        cout<<x-v.at(j)<<endl;
        return 0;
      }
    }
    cout<<0<<endl;
  }
}