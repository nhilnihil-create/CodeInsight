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
  int x=0,N, out=0;
  string S;
  cin >> N >> S;
  for (int i=0; i < N; i++) {
    if (S[i] == 'I') x++;
    else x--;
    out = max(out ,x);
  }
  cout << out << endl;
  return 0;
}
