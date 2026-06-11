#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  string S;
  cin >> S;
  int count = 0, intercount = 0;
  rep(i, N) {
    if (S.at(i) == 'a') {
      if (count < A + B) {
        cout << "Yes" << endl;
        count++;
      }
      else cout << "No" << endl;
    }
    else if (S.at(i) == 'b') {
      if (count < A + B && intercount < B) {
        cout << "Yes" << endl;
        count++;
        intercount++;
      }
      else cout << "No" << endl;
    }
    else cout << "No" << endl;
  }
}
