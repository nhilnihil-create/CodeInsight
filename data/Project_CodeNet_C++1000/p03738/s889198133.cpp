#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string a,b;cin>>a>>b;
  int c=a.size(),d=b.size();
  if(c>d){
    cout<<"GREATER"<<endl;
    return 0;
  }
  else if(c<d){
    cout<<"LESS"<<endl;
    return 0;
  }
  else {
    rep(i,c){
      if(a[i]==b[i])continue;
      else if(a[i]>b[i]){
        cout<<"GREATER"<<endl;
        return 0;
      }
      else {
        cout<<"LESS"<<endl;
        return 0;
      }
    }
  }
  cout<<"EQUAL"<<endl;
}
