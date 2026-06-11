#include <iostream>
#include <string>
using namespace std;
int main()
{
  string S;
  cin >> S;
  int len = S.length();
  for (int i = 1; i < len; i++) {
    int len1 = (len-i)/2;
    int len2 = len-i-len1;
    if (len1!=len2) continue;

    string s1 = S.substr(0, len1);
    string s2 = S.substr(len1, len2);
    if (s1==s2) {
      cout << len1+len2 << endl;
      return 0;
    }
  }
}
