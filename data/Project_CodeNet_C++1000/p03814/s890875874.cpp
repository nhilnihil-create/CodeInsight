#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  string s;
  cin>>s;
  int a=0;
  int z=s.size();
  rep(i,s.size()){
    if(s[i]=='A') break;
    a++;
  }
  for(int i=s.size()-1;i>0;i--){
    if(s[i]=='Z') break;
    z--;
  }
  cout<<z-a<<endl;
}