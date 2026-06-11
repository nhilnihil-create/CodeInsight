#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n; cin>>n;
  long long t; cin>>t;
  int tmp,b_0,b_1,e_0,e_1;
  long long ans = t;
  b_0 = 0;
  e_0 = t;
  for (int i=0;i<n;i++) {
    cin >> tmp;
    b_1 = tmp;
    e_1 = tmp + t;
    if (b_1 < e_0) ans -= e_0 - b_1;
    ans += t;
    b_0 = b_1;
    e_0 = e_1;
  }
  cout << ans << endl; 
}