#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> v(1e5+2, 0);
  rep(i, n){
    ++v[a[i]];
    ++v[a[i] + 1];
    ++v[a[i] + 2];
  }
  vector<int>::iterator ans = max_element(v.begin(), v.end());
  cout << *ans << endl;
  return 0;
}