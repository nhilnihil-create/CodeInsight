#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  char a,b;
  cin >> a >>b;
  if((a == 'H' && b == 'H') || (a=='D' && b =='D')) cout << "H" << endl;
  else cout << "D" << endl;
}