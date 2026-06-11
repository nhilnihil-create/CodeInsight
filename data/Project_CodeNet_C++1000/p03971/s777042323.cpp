#include <iostream>
#include <string>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  string S;
  cin >> S;
  int n = 0, b = 0;
  for (int i=0; i < S.size(); i++) {
    if (S[i] == 'a') {
      if (n < A+B) {
	cout << "Yes" << endl;
	n++;
      } else {
	cout << "No" << endl;
      }
    } else if (S[i] == 'b') {
      if (n < A+B && b < B) {
	cout << "Yes" << endl;
	n++;
	b++;
      } else {
	cout << "No" << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }
}

