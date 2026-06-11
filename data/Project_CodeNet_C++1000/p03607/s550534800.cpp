#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  
  int a;
  map<int,int> b;
  for(int i=0; i<n; i++) {
    cin >> a;
    b[a]++;
  }
  
  int ans = 0;
  for(auto p : b) if(p.second%2!=0) ans++;
  
  cout << ans << endl;
  return 0;
}