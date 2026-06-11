#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> a(3);
  cin>>a.at(0)>>a.at(1)>>a.at(2);
  sort(a.begin(),a.end());
  int ans=1;
  for(int i=0;i<2;i++){
    if(a.at(i)!=a.at(i+1)){
      ans++;
    }
  }
  cout<<ans<<endl;
}
