#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  int cnt1=0;
  rep(i,s.size()){
    if(s[i]=='A')break;
    cnt1++;
  }
  int cnt2=0;
  for(int i=s.size()-1;i>0;i--){
    if(s[i]=='Z')break;
    cnt2++;
  }
  cout<<s.size()-cnt1-cnt2<<endl;
}