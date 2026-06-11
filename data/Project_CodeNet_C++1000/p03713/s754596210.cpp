#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  long long h, w;
  cin >> h >> w;
  
  long long a, b, c, ans = 1e15;
  
  for(int i = 1; i < h; i++){
    a = i * w;
    b = (w / 2) * (h - i);
    c = h * w - a - b;
    ans = min(ans, max({a, b, c}) - min({a, b, c}));
    
    b = ((h - i) / 2) * w;
    c = h * w - a - b;
    ans = min(ans, max({a, b, c}) - min({a, b, c}));
  }
  
  for(int i = 1; i < w; i++){
    a = i * h;
    b = (h / 2) * (w - i);
    c = h * w - a - b;
    ans = min(ans, max({a, b, c}) - min({a, b, c}));
    
    b = ((w - i) / 2) * h;
    c = h * w - a - b;
    ans = min(ans, max({a, b, c}) - min({a, b, c}));
  }
  
  cout << ans << "\n";
}