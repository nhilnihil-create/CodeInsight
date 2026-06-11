#include <iostream>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  
  ll power = 1;
  for (int i = 1; i <= n; i++) power = (power * i) % (1000000007);
  
  cout << power << endl;
}