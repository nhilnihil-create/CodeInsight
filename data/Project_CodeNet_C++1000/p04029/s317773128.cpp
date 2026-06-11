#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  int sum = 0;
  rep(i, 1, n+1) {
    sum += i;
  }
  cout << sum << "\n";
}
