#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <deque>

using namespace std;
const long long P = 1000000007;

int main() {
  int n;
  cin >> n;
  long long a[n],b[n];
  long long count = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for(int i = n-1; i >= 0; i--) {
    a[i] += count;
    if(a[i] % b[i] != 0) {
      count += b[i] - (a[i] % b[i]);
    }
  }
  cout << count << endl;
  return 0;
}