#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int a,b,c;cin>>a>>b>>c;
  for(int i=1;i<b;i++){
    int d=a*i;
    if(d%b==c){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
}