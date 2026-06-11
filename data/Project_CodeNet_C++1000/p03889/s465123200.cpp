#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
 cin.tie(0);
 ios::sync_with_stdio(false); 
  string s,w;
  cin>>s;
  w=s;
  bool f=false;
  reverse(w.begin(),w.end());
  if(s==w)f=true;
  for(int i=0;i<s.length();i++){
    if(w.substr(i,1)=="b"){
      w.replace(i,1,"d");
    }else if(w.substr(i,1)=="d"){
      w.replace(i,1,"b");
    }else if(w.substr(i,1)=="p"){
      w.replace(i,1,"q");
    }else if(w.substr(i,1)=="q"){
      w.replace(i,1,"p");
    }
  }
  if(s==w)f=true;
  if(f){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl; 
  }
  return 0; 
}

