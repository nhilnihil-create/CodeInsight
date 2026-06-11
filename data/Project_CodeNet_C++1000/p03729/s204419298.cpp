#include <iostream>
using namespace std;

int main() {
  string A, B, C;
  cin >> A >> B >> C;

  string result = "NO";
  if (A[A.size() - 1] == B[0]) {
    if (B[B.size() - 1] == C[0]) {
      result = "YES";
    }
  };
  cout << result << endl;
  return 0;
}
