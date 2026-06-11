#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  for (int i = 0; i < S.length() - 1; i ++){
    if (S[i] == ','){
      S[i] = ' ';
    }
  }
  cout << S << '\n';
}