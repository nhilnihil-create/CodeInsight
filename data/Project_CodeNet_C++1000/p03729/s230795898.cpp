#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  string A, B, C;
  cin >> A >> B >> C;

  if (A[A.size() - 1] == B[0] && B[B.size() -1] == C[0]) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
