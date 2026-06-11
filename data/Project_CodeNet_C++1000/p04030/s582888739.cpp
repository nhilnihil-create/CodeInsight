#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int M = S.size();
  vector<char>s(M,'2');
  int A = 0;
  for (int i = 0; i < M; i++) {
    if (S.at(i) == '0'){
      s.at(A) = '0';
      A++;
    }
    else if (S.at(i) == '1'){
      s.at(A) = '1';
      A++;
    }
    else if (S.at(i) == 'B'){
      if (A != 0){
        s.at(A-1) = '2';
        A--;
      }
    }
  }
  for (int i = 0; i < M; i++) {
    if (s.at(i) != '2'){
      cout << s.at(i);
    }
  }
  cout << endl;
}