#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  int n=s.size();
  int l=0,r=0;
  rep(i,n){
    if(s[i]=='A')break;
    l++;
  }
  for(int i=n-1;i>0;i--){
    if(s[i]=='Z')break;
    r++;
  }
  cout<<n-(l+r)<<endl;
}