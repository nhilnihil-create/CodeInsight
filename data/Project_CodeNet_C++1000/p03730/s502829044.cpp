#include <iostream>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  if (A == 1) {
    cout << "YES" << endl;
    return 0;
  }

  int B_apper[B];
  for (int i=0; i<B; i++) B_apper[i] = 0;
  int k = 1;
  while(1) {
    int mod = (k*A) % B;
    if (mod == C) {
      cout << "YES" << endl;
      return 0;
    } else if (B_apper[mod] == 1) {
      cout << "NO" << endl;
      return 0;
    }
    B_apper[mod] = 1;
    k++;
  }
}