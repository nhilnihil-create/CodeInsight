
#include <bits/stdc++.h>  
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n; cin>>n;
  string s; cin>>s;
  string t; t=s;
  int i=0;
  while(i<t.size()-1){
    if(t[i]=='(' && t[i+1]==')'){
      t.erase(i,2);
      if(t.size()==0)break;
      if(i>0){i--;}
    }
    else{i++;}
  }
  int a=count(t.begin(),t.end(),'(');
  int b=t.size()-a;

  
  rep(j,b){cout<<"(";}
  cout<<s;
  rep(j,a){cout<<")";}
  
  cout<<endl;
}