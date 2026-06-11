#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int64_t n,t;
  cin >> n >> t;
  vector<int64_t> vec(n);
  rep(i,n){
    cin >> vec.at(i);
  }
  int64_t ans=t;
  rep(i,n-1){
    ans+=min(vec.at(i+1)-vec.at(i),t);
  }
  cout << ans;
}