#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,k;cin>>n>>k;
  vector<int> l(n);
  rep(i,n)cin>>l[i];
  sort(all(l));
  reverse(all(l));
  int cnt=0;
  rep(i,k){
    cnt+=l[i];
  }
  cout<<cnt<<endl;
}