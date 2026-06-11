#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;

int main() {
  vector<int> V(3);
  cin >> V[0] >> V[1] >> V[2];
  sort(V.begin(), V.end());
  if (V[0]==5 && V[1]==5 && V[2]==7) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}