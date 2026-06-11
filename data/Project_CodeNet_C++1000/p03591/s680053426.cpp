#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
  int i;
  string s,f="YAKI";
  cin >> s;
  for (i=0;i<4;i++) if (s.size()<4 || s[i]!=f[i]) break;
  if (i==4) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}