#include <bits/stdc++.h>
using namespace std;
int main(){
string N;
  cin>>N;
  bool nazo=false;
  for(int i=0;i<N.size();i++){
  if(N.at(i)=='9'){
  nazo=true;
    break;
 	 }
  }
  if(nazo){
  cout<<"Yes"<<endl;
  }
  else{
  cout<<"No"<<endl;
  }
}