#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  cout << (n == 1 ? k : (ll)(k * pow(k-1, n-1))) << endl;
}