#include <bits/stdc++.h>
#include <algorithm>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  string W;
  cin>>W;
  
  vector<char> vec(W.size());
  for(int i=0;i<W.size();i++){
    vec[i]=W[i];
  }
  
  vector<int> num(26);
  for(int i=0;i<26;i++){
    num[i]=count(vec.begin(),vec.end(),'a'+i);
  }
  
  bool res=true;
  
  
  for(int i=0;i<26;i++){
    if(num[i]%2!=0){
      res=false;
      break;
    }
  }
  
  if(res){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}