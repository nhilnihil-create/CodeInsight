#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  int n = 0, w = 0, s = 0, e = 0;
  int a = S.size();
  for (int i = 0; i < a; i++){
    if (S[i] == 'N') n++;
    if (S[i] == 'W') w++;
    if (S[i] == 'S') s++;
    if (S[i] == 'E') e++;
  }
  bool flag = true;
  if ((n > 0 && s == 0) || (n == 0 && s > 0)) flag = false;
  if ((w > 0 && e == 0) || (w == 0 && e > 0)) flag = false;
  
  if (flag == true) cout << "Yes" << endl;
  else cout << "No" << endl;
}