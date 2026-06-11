#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n),b(n),c(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i) >> b.at(i);
    c.at(i) = a.at(i);
  }
  sort(c.begin(),c.end());
  int k;
  for(int i=0;i<n;i++){
    if(a.at(i) == c.at(n-1)){
      k = i;
      break;
    }
  }
  int ans = b.at(k) + a.at(k);
  cout << ans << endl;
  return 0;
}
