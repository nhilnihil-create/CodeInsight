#include<bits/stdc++.h>
using namespace std;
int main(){
  int m,k,j,x=0;
  cin>>m>>k;
  vector<int> t(m);
  for(j=0;j<m;j++){
    cin>>t.at(j);
    if(j==0) x+=k;
    else x+=min(k,t.at(j)-t.at(j-1));
  }
  cout<<x<<endl;
}