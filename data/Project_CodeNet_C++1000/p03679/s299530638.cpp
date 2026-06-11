#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <deque>
#include <stack>

using namespace std;
const long long P = 1000000007;

int main() {
  long long x,a,b;
  cin >> x >> a >> b;
  if(b-a <= 0) {
    cout << "delicious" << endl;
  }else if(b-a <= x) {
    cout << "safe" << endl;
  }else {
    cout << "dangerous" << endl;
  }
  return 0;
}
