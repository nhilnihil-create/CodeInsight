#include<iostream>
using namespace std;

int main() {
  int N; string S;
  cin >> N >> S;
  int level = 0, beginc = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == '(') level++;
    else {
      if (--level < 0) {
        level = 0;
        beginc++;
      }
    }
  }
  cout << string(beginc, '(') << S << string(level, ')');
}