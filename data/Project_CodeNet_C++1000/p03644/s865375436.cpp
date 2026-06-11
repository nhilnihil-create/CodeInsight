#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  int ans=-1,a;
  for(int i=1;i<=n;i++){
    int cnt=0,j=i;
    while(j){
      if(j%2==0)cnt++;
      j/=2;
    }
    if(cnt>ans){
      ans=cnt;
      a=i;
    }
  }
  cout<<a<<endl;
}