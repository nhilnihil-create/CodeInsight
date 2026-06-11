#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  int x,a,b;
  cin >> x >> a >> b;

  if(b-a <= 0) cout << "delicious" << endl;
  else if(b-a <= x) cout << "safe" << endl;
  else cout << "dangerous" << endl;
}