#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,a,b;string s;cin>>n>>a>>b>>s;
  int cnt=0,B=0;
  rep(i,n){
    if(s[i]=='c')cout<<"No"<<endl;
    else {
      if(s[i]=='a'){
        if(cnt<a+b){
          cout<<"Yes"<<endl;
          cnt++;
        }
        else cout<<"No"<<endl;
      }
      else {
        if(B<b&&cnt<a+b){
          cout<<"Yes"<<endl;
          cnt++;
        }
        else cout<<"No"<<endl;
        B++;
      }
    }
  }
}