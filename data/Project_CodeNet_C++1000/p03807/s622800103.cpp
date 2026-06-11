#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> a(n);
  int cnt=0;
  rep(i,n){
    cin>>a[i];
    if(a[i]%2==1)cnt++;
  }
  if(cnt%2==0)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}