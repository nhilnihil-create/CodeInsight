#include <iostream>

using namespace std;

typedef long long ll;

ll evp (ll x) {
  if (x < 0) return -100;
  return x - x % 2;
}

int main () {
  ll I, O, T, J, L, S, Z;
  cin >> I >> O >> T >> J >> L >> S >> Z;

  ll ans_a = 3 + evp(L - 1) + evp(J - 1) + evp(I - 1);
  ll ans_b = evp(L) + evp(J) + evp(I);

  ll ans = max(ans_a, ans_b) + O;
  
  cout << ans << endl;
}
