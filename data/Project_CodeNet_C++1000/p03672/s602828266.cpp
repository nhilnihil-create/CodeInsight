#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  string s;
  cin >> s;
  ll ans=0;
  for(int i=0;i<s.size()-1;i++){
    s=s.substr(0,s.size()-1);
    if(s.size()%2==1){
      continue;
    }
    bool is=true;
    for(int j=0;j<s.size()/2;j++){
      if(s.at(j)!=s.at(j+s.size()/2)){
        is=false;
      }
    }
    if(is){
      ans=s.size();
      break;
    }
  }
  ll q=2;
  cout << max(ans,q);
}