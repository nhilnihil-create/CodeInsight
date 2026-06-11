#include <bits/stdc++.h>
using namespace std;


int main() {
  int N, M;
  cin >> N >> M;
  
  int a, b;
  vector<int> x(N);
  for (int i=0; i<M; i++) {
    cin >> a >> b;
    x.at(a-1) += 1;
    x.at(b-1) += 1;
  }
  
  //sort(x.begin(), x.end());
  for (auto n : x) {
    cout << n << endl;
  }
  
  return 0;
}
