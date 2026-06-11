#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<string,int>;

int main(){
  int n;
  cin >> n;
  vector<int> l(2*n);
  rep(i,2*n) cin >> l[i];
  sort(l.begin(),l.end());
  int ans = 0;
  rep(i,2*n){
    if(i%2 == 0){
      ans += min(l[i],l[i+1]);
    }
  }
  cout << ans << endl;
  return 0;
}
