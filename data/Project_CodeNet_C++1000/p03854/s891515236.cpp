#include <algorithm>
#include <iostream>
using namespace std;
#define R(x) rbegin(x), rend(x)
string a{"dream"}, b{"dreamer"}, c{"erase"}, d{"eraser"};
int main() {
  string S;
  cin >> S;
  auto i = S.rbegin(), e = S.rend();
  while (i != e)
    if (equal(R(a), i) || equal(R(c), i)) i += 5;
    else if (equal(R(b), i)) i += 7;
    else if (equal(R(d), i)) i += 6;
    else break;
  cout << (i == e ? "YES" : "NO") << endl;
}
