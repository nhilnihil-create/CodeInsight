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
  int a, b, c;
  cin >> a >> b >> c;
  if(b-a == c-b) cout << "YES\n";
  else cout << "NO\n";
}
