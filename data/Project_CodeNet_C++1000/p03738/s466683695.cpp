#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;

int main() {
  string a, b;
  cin >> a >> b;

  if (a.size() > b.size()) {
    cout << "GREATER" << endl;
  } else if (a.size() < b.size()) {
    cout << "LESS" << endl;
  } else {
    if (a > b) {
      cout << "GREATER" << endl;
    } else if (a < b)  {
      cout << "LESS" << endl;
    } else {
      cout << "EQUAL" << endl;
    }
  }
  return 0;
}