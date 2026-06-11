#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int a,b,c,d;cin>>a>>b>>c>>d;
  int cnt1=max(a,c),cnt2=min(b,d);
  int ans=max(0,cnt2-cnt1);
  cout<<ans<<endl;
}