#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  vector<int>a(3,0);
  int tmp;
  for(int i=0;i<n;i++){
    cin>>tmp;
    if(tmp%4==0)a.at(0)++;
    else if(tmp%2==0)a.at(1)++;
    else a.at(2)++;
  }
  bool ans=false;
  if(a.at(1)==1)a.at(2)++;
  if(a.at(1)==0||a.at(1)==1){
    if(a.at(0)+1>=a.at(2)){
      cout <<"Yes"<<endl;
      return 0;
    }
    else{
      cout <<"No"<<endl;
      return 0;
    }
  }
  else{
    if(a.at(0)>=a.at(2)){
      cout <<"Yes"<<endl;
      return 0;
    }
  }
  cout <<"No"<<endl;
}