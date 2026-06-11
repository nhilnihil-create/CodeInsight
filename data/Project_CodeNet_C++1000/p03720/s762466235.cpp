#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M;
  cin >> N >> M;
  
  vector<int> cities(N);
  for (int m = 0; m < M; m++) {
    int a, b;
    cin >> a >> b;
    cities.at(a - 1) = cities.at(a - 1) + 1;
    cities.at(b - 1) = cities.at(b - 1) + 1;
  }
  for (int n = 0; n < N; n++) {
    cout << cities.at(n) << endl;
  }
}
