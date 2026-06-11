#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 
  
  int h, w;
  cin >> h >> w;

  for (int i = 0; i < w + 2; ++i) cout << "#";
  cout << "\n";

  for (int i = 0; i < h; ++i) {
    cout << "#";
    for (int j = 0; j < w; ++j) {
      char c; cin >> c;
      cout << c;
    }
    cout << "#\n";
  }

  for (int i = 0; i < w + 2; ++i) cout << "#";
  cout << "\n";
}
