#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  string t="NWSE";
  vector<int> vec(4);
  rep(i,s.size()){
    rep(j,4){
      if(s[i]==t[j])vec[j]++;
    }
  }
  bool ok=true;
  rep(i,2){
    if((vec[i]==0&&vec[i+2]>0)||(vec[i+2]==0&&vec[i]>0))ok=false;
  }
  if(ok)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}