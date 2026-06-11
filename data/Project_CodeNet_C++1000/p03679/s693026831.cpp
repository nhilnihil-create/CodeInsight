#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#define ill long long
#define rep(i, a, b) for(ill i = (ill)(a); i < (ill)(b); i++)
#define fcout cout << fixed << setprecision(10)
using namespace std;

int main() {
  int x, a, b;
  cin >> x >> a >> b;
  if(a >= b) cout << "delicious\n";
  else if(a+x >= b) cout << "safe\n";
  else cout << "dangerous\n";
}
