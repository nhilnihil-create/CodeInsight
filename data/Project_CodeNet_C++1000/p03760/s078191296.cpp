#include<vector>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main(){
  string o,n;
  cin>>o>>n;
  for(int i=0;i<o.size()-1;++i){
    cout<<o[i]<<n[i];
  }
  cout<<o[o.size()-1];
  if(o.size()==n.size()) 
    cout<<n[n.size()-1];
  cout<<endl;
}