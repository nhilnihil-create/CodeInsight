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
#include <sstream>

using namespace std;
const long long P = 1000000007;
const long long INF = 1LL << 60;

int main() {
  int n;
  cin >> n;
  int count2 = 0;
  int count4 = 0;
  long long a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] % 4 == 0) {
      count4++;
    }else if(a[i] % 2 == 0) {
      count2++;
    }
  }
  int others = n - (count4 + count2);
  if(others <= count4 || (count2 == 0 && others <= count4+1)) {
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }
  return 0;
}
