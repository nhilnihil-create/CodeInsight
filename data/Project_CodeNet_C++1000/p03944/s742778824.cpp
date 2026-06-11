#include <bits/stdc++.h>
using namespace std;

int main() {
  int min_x = 0, max_x, min_y = 0, max_y, N;
  int x, y, a;
  cin >> max_x >> max_y >> N;

  for(int i = 0; i < N; i++) {
    cin >> x >> y >> a;
    if(a == 1 && x > min_x) min_x = max(min_x, x);
    else if(a == 2) max_x = min(max_x, x);
    else if(a == 3) min_y = max(min_y, y);
    else if(a == 4) max_y = min(max_y, y);
  }
  if(max_x-min_x <= 0 || max_y-min_y <= 0) cout << 0 << endl;
  else cout << (max_x-min_x) * (max_y-min_y)<< endl;
}

