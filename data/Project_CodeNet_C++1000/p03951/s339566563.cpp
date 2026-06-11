#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n;
  cin>>n;
  string s,t;
  cin >> s>>t;
  int co=0;
  int ans=0;
  rep(i,n){
    int co=0;
    rep(j,n-i){
      if(t.at(j)==s.at(j+i)){
        co++;
      }
      else{
        ans=max(ans,co);
        co=0;
      }
    }
    ans=max(ans,co);
  }
  
  cout<<n*2-ans<<endl;
 
}