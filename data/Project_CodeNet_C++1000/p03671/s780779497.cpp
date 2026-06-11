#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> V(3);
  for (int i=0; i<3; i++) {
    cin >> V[i];
  }
  sort(V.begin(), V.end());
  cout << V[0]+V[1] << endl;
}
