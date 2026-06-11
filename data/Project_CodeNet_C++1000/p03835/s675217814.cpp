#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  int K, S, C=0;
  cin >> K >> S;
  for (int x=0; x<=min(K, S); x++) {
    for (int y=0; y<=min(K, S); y++) {
      if (S-(x+y)>=0 && S-(x+y)<=K) {
        C++;
      }
    }
  }
  cout << C << endl;
}