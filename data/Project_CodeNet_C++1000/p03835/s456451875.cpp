#include <iostream>
using namespace std;
typedef long long ll;
ll K, S;

ll solve() {
  ll x, y, z, res = 0;
  for(x = 0; x <= K; x++) {
    for(y = 0; y <= K; y++) {
      if(S - x - y <= K && S - x - y >= 0) res++;
    }
  }
  return res;
}

int main() {
  cin >> K >> S;
  cout << solve() << endl;
}