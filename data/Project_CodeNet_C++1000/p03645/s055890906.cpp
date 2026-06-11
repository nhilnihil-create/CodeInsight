#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<int> from1;
  vector<int> toN;
  
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;

    if (x == 1) from1.push_back(y);
    if (y == N) toN.push_back(x);
    
  }
  
  sort(from1.begin(), from1.end());
  sort(toN.begin(), toN.end());
  

  vector<int> v;
  set_intersection(from1.begin(), from1.end(), toN.begin(), toN.end(), back_inserter(v));
  
  if (v.size()) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}