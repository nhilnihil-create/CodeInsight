#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  
  cout << max(A*B, C*D) << endl;
}