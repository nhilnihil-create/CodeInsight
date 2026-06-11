#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)        for(int i=0; i<(int)(n); ++i)

int main(){
  int n;
  string a,b;
  cin>>n>>a>>b;
  int kotae=0;
  for(int i=a.size();i>=0;i--){
    string s,t;
    s=a.substr(a.size()-i,i);
    t=b.substr(0,i);
      if(s==t){
        kotae=a.size()+b.size()-i;
        break;
      }
  }
  cout<<kotae<<endl;
  return 0;
}