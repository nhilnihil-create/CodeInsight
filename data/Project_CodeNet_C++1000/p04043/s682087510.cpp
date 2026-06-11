#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  
  vector<int> length(11, 0);
  
  length[A]++;
  length[B]++;
  length[C]++;
  
  if (length[5] == 2 && length[7] == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  
}