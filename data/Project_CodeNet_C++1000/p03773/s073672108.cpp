#include <iostream>
#include <vector>
#define rep(i,n) for (int i = 0; (i) < int(n); ++(i))
using ll = long long;
using namespace std;
const ll mod = 1000000007;

int main() {

  ll A,B; cin >> A >> B;

  ll c = A + B;

  while(c >= 24) {
    c -= 24;
  }

  cout << c << endl;
}