#include <iostream>
#include <string>
using namespace std;
int main()
{
  string S;
  cin >> S;
  int alpha[26] = {0};
  for (int i = 0; i < S.length(); i++) {
    alpha[(int)(S[i]-'a')]++;
  }
  bool ans = true;
  for (int i = 0; i < 26; i++) {
    if (alpha[i]>1) ans = false;
  }
  if (ans) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
  return 0;
}
