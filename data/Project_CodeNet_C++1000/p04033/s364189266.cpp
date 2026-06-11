#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  int a, b;
  cin >> a >> b;

  if (a <= 0 && 0 <= b) {
    cout << "Zero";
  } else if (a > 0) {
    cout << "Positive";
  } else {
    if ((-a+b+1) % 2 == 0) {
      cout << "Positive";
    } else {
      cout << "Negative";
    }
  }

  cout << endl;
  return 0;
}
