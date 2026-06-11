#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y){
  if(x % y == 0) return y;
  
  int next = x % y;
  return gcd(y, next);
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  
  sort(a.begin(), a.end());
  int mi = a.at(0);
  for(int i = 1; i < n; i++){
    mi = gcd(mi, a.at(i));
    if(mi == 1) break;
  }
  
  if(k % mi || k > a.at(n-1)) cout << "IMPOSSIBLE" << endl;
  else cout << "POSSIBLE" << endl;
}