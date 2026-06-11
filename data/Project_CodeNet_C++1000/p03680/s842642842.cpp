#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
    a[i]--;
  }
  int cnt=0,ans=a[0];
  rep(i,n){
    cnt++;
    if(ans==1){
      cout<<cnt<<endl;
      return 0;
    }
    ans=a[ans];
  }
  cout<<-1<<endl;
}