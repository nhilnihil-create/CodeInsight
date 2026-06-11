#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  string S;
  cin >> N >> A >> B;
  cin >> S;
  int count = 0;
  int bcount = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == 'a') {
      // 国内の学生
      if (A + B > count) {
        count ++;
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    } else if (S[i] == 'b') {
      if (A + B > count && bcount < B) {
        count ++;
        bcount++;
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
      // 海外の学生
    } else if (S[i] == 'c') {
      // 学生でない
	  cout << "No" << endl;
    }
  }
}