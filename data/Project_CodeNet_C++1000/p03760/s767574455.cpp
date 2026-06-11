#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string a,b;cin>>a>>b;
  rep(i,a.size()){
    cout<<a[i];
    if(i<b.size())cout<<b[i];
  }
  cout<<endl;
}
