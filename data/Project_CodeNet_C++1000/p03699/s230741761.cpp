#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
  #include "_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

signed main(){

  int n; cin >> n;
  vector<int> a(n), b(n);
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
    if(a[i] % 10 != 0) b.push_back(a[i]);
  }
  
  if(sum % 10 == 0){
    sort(b.begin(), b.end());
    for(int i = 0; i < b.size(); i++){
      if(b[i] % 10 != 0){
        sum -= b[i];
        break;
      }
    }
  }
  if(sum % 10 == 0) sum = 0;
  cout << sum << endl;

  return 0;
}