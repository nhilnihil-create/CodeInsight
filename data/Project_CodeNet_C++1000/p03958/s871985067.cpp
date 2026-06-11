#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<string,int>;

int main(){
  int k,t;
  cin >> k >> t;
  vector<int> a(t);
  int b = 0;
  rep(i,t){
    cin >> a[i];
    b = max(b,a[i]);
  }
  sort(a.rbegin(),a.rend());
  int c = k-b;
  int ans = max(0,b-c-1);
  cout << ans << endl;
  return 0;
}
