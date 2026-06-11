#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;

int main() {
  string O, E;
  cin >> O;
  cin >> E;
  int s, t;
  s = 0;
  t = 0;
  for(int i = 0; i < O.size() + E.size(); i++) {
    if(i % 2 == 0) { cout << O[s]; s++; }
    else { cout << E[t]; t++; }
  
  }
  return 0;
}