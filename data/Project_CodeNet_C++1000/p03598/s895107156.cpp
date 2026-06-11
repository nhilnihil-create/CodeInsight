#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  int x[n];
  for(int i = 0; i < n; i++) {
    cin >> x[i];
  }

  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += 2*min(x[i],k-x[i]);
  }

  cout << sum << endl;
  return 0;
}
