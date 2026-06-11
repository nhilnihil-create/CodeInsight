#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  int n=s.size();
  rep(i,n){
    s.pop_back();
    int x=s.size();
    if(s.substr(0,x/2)==s.substr(x/2)){
      cout<<s.size()<<endl;
      return 0;
    }
  }
}