#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int kotae=0;
  for(int i=s.size()-1;i>=2;i=i-2){
    string a=s.substr(0,i/2);
    string b=s.substr(i/2,i/2);
    if(a==b){
      kotae=a.size()*2;
      break;
    }
  }
  cout<<kotae<<endl;
  return 0;
}

  
