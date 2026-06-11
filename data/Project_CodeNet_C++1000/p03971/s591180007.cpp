#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main () {
  int N, A, B;
  cin >> N >> A >> B;

  string S;
  cin >> S;
  
  int passed_all = 0;
  int passed_foreign = 0;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == 'a') {
      if (passed_all < A+B) {
        cout << "Yes" << endl;
        passed_all++;
      } else {
        cout << "No" << endl;
      }
    } else if (S.at(i) == 'b') {
      if (passed_all < A+B && passed_foreign < B) {
        cout << "Yes" << endl;
        passed_foreign++;
        passed_all++;
      } else {
        cout << "No" << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }
}