#include <iostream>
#include <string>
using namespace std;
int main()
{
  bool alpha[26] = {false};
  string S;
  cin >> S;
  for (int i = 0; i < S.length(); i++) {
    char c = S[i];
    alpha[(int)(c-'a')] = true;
  }
  for (int i = 0; i < 26; i++) {
    if (!alpha[i]) {
      cout << (char)(i+'a') << endl;
      return 0;
    }
  }
  cout << "None" << endl;
  return 0;
}
