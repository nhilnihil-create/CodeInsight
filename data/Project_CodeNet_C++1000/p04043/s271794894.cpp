#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> iroha(3);
  for (int i = 0; i < 3; i++) cin >> iroha[i];
  cout << 
    (count(iroha.begin(), iroha.end(), 5) == 2 && count(iroha.begin(), iroha.end(), 7) == 1 ? "YES" : "NO")
    << endl;
}