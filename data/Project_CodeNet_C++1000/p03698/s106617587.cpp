#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin>>s;
  set<char> t;
  bool ans=true;
  rep(i,s.size()){
    char u=s[i];
    if(t.count(u)){
      ans=false;
    }
    t.insert(u);
  }
  if(ans){
    cout<<"yes"<<endl;
  }else{
    cout<<"no"<<endl;
  }
}