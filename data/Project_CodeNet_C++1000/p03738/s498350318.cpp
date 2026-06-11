#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string a,b;cin>>a>>b;
  int x=a.size(),y=b.size();
  if(x>y)cout<<"GREATER"<<endl;
  else if(x<y)cout<<"LESS"<<endl;
  else {
    rep(i,x){
      if(a[i]<b[i]){
        cout<<"LESS"<<endl;
        return 0;
      }
      else if(a[i]>b[i]){
        cout<<"GREATER"<<endl;
        return 0;
      }
    }
    cout<<"EQUAL"<<endl;
  }
}