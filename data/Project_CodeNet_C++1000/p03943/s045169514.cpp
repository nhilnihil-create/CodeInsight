#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;

int main() {
  vector<int> V(3);
  for (int i=0; i<3; i++) {
    cin >> V[i];
  }
  sort(V.begin(), V.end());
  if (V[0]+V[1]==V[2]) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}