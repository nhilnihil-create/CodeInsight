#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.length();
  cout << S[0] << N - 2 << S[N - 1] << endl;
}
