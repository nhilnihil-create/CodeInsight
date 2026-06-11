#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  string n;
  cin >> n;

  if (n.at(0) == '9' || n.at(1) == '9') {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
