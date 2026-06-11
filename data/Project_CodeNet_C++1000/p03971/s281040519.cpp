#include <iostream>
#include <string>
using namespace std;

int main() {
  int N, A, B;
  string S;
  cin >> N >> A >> B;
  cin >> S;
  int pass = 0;
  int passb = 0;
  for(int i = 0; i < S.length(); i++) {
    if(S[i] == 'c') cout << "No" << endl;
    else {
      if(S[i] == 'a' && pass < (A + B)) {
        pass++;
        cout << "Yes" << endl;
      } else if(S[i] == 'b' && pass < (A + B) && passb < B) {
        pass++;
        passb++;
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}