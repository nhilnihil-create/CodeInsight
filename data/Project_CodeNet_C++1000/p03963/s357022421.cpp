#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("../data.txt");

int n, k, ans;


int main() {

  cin >> n >> k;
  ans = k;
  for (int i = 1; i < n; i++) {
    ans *= (k-1);
  }

  cout << ans;

  return 0;
}
