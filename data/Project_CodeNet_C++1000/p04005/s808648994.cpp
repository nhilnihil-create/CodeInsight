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
  ull a, b, c;
  cin >> a >> b >> c;
  
  if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) {
    cout << 0 << endl;
  } else {
    cout << min(a*b, min(b*c, a*c)) << endl;
  }
  return 0;
}