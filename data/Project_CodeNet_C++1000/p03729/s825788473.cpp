#include <iostream>
using namespace std;
int main() {
	string A, B, C;
	cin >> A >> B >> C;
	cout << ((A.back() == B[0] && B.back() == C[0]) ? "YES" : "NO") << endl;
  return 0;
}