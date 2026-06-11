#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int mod=1000000007;
  int n;
  cin >> n;
  vector<int>a(n);
  vector<int>b(n);
  rep(i,n){
    cin>>a.at(i);
  }
  rep(i,n){
    cin>>b.at(i);
  }
  bool ch=true;
  rep(i,n-1){
    if(a.at(i+1)!=a.at(i)&&a.at(i+1)>b.at(i+1)){
      ch=false;
    }
    if(b.at(i+1)!=b.at(i)&&a.at(i)<b.at(i)){
      ch=false;
    }
  }
  if(a.at(n-1)!=b.at(0)){
    ch=false;
  }
  if(ch){
    long ans=1;
    rep(i,n-2){
      if(a.at(i)==a.at(i+1)&&b.at(i+2)==b.at(i+1)){
        ans*=min(a.at(i+1),b.at(i+1));
        ans%=mod;
      }
    }
    cout<<ans<<endl;
  }
  else{
    cout<<0<<endl;
  }
  
}