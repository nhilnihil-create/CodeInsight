#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  while(1){
    s.pop_back();
    int n=s.size();
    if(s.substr(0,n/2)==s.substr(n/2)){
      cout<<n<<endl;
      return 0;
    }
  }
}