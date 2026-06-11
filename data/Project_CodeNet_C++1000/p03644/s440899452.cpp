#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  int ans=1,cnt1=0;
  for(int i=1;i<=n;i++){
    int cnt=0,a=i;
    while(1){
      if(a%2==1)break;
      a/=2;
      cnt++;
    }
    if(cnt1<cnt){
      cnt1=cnt;
      ans=i;
    }
  }
  cout<<ans<<endl;
}