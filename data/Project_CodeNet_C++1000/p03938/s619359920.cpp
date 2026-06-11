#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> la(n), lb(n);
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    la[i] += i*20000+1;
    lb[i] += (n-i-1)*20000+1;
    lb[p-1] += i;
  }
  for (int i = 0; i < n; ++i) {
    cout << la[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < n; ++i) {
    cout << lb[i] << " ";
  }
  cout << endl;
}