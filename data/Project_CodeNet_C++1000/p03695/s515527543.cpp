#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> vec(20);
  rep(i,n){
    int a;cin>>a;
    vec[a/400]++;
  }
  int cnt1=0,cnt2=0;
  rep(i,20){
    if(i>7)cnt2+=vec[i];
    else {
      if(vec[i]>0)cnt1++;
    }
  }
  if(cnt1==0)cout<<1<<" "<<cnt2<<endl;
  else cout<<cnt1<<" "<<cnt1+cnt2<<endl;
}