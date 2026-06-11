#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  string tmp,tmp2;
  cin >>s;
  int64_t ans=0,a=s.size();
  for(int64_t bit=0;bit<(1<<a-1);bit++){
    tmp="";
    for(int64_t j=0;j<a-1;j++){
      tmp+=s.at(j);
      if(bit>>j&1){
        tmp+="+";
      }
    }
    tmp+=s.at(a-1);
    tmp2="";
    for(int64_t i=0;i<tmp.size();i++){
      if(tmp.at(i)!='+'){
      	tmp2+=tmp.at(i);
      }
      else{
        ans+=stol(tmp2);
        tmp2="";
      }
      if(i==tmp.size()-1&&tmp2!="")
        ans+=stol(tmp2);
    }
  }
  cout <<ans<<endl;
}