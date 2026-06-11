#include<bits/stdc++.h>
using namespace std;
int main(){
  string O,E;
  cin>>O>>E;
  string ans;
  for(int i=0;i<O.size()-1;i++){
    ans+=O.at(i);
    ans+=E.at(i);
  }
  if(O.size()-E.size()==0){
    ans+=O.at(O.size()-1);
    ans+=E.at(E.size()-1);
  }
  else{
    ans+=O.at(O.size()-1);
  }
  cout<<ans<<endl;
}