#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  string S;
  cin >> N >> S;
  int f = 0, b = 0;
  for (int i = 0; i < (int) S.size(); i++) {
    if (S.at(i) == '(') {
      f++;
    }
    else {
      b++;
    }
    if (f < b) {
      S = '(' + S;
      f++;
      i++;
    }
  }
  for (int i = 0; i < f - b; i++) {
    S += ')';
  }
  cout << S << endl;
}