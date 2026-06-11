#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string a,b;
  cin>>a>>b;
  int c,d;
  c=a.size();d=b.size();
  string ans="EQUAL";
  if(c<d){
    ans="LESS";
  }else if(d<c){
    ans="GREATER";
  }else{
      rep(i,c){
          if(a[i]<b[i]){
            ans="LESS";
            break;
          }else if(b[i]<a[i]){
            ans="GREATER";
            break;
          }
      }
  }
  cout<<ans<<endl;
}