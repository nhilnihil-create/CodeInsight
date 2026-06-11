#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;
typedef long long ll;

int main() {
  string S;
  getline(cin, S);
  int ap,zp;
  int i=0;
  while(S[i]!='A')i++;
  ap = i;
  i = S.length()-1;
  while(S[i]!='Z')i--;
  zp = i;
  cout << zp - ap + 1 << endl;
  return 0;
}
