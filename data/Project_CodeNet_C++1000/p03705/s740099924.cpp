#include <iostream>

using namespace std;

int main() {
  long long N, A, B;
  cin >> N >> A >> B;
  long long ans;
  if (A > B)
    ans = 0;
  else if (N == 1 && A != B)
    ans = 0;
  else
    ans = (N - 2) * (B - A) + 1;
  cout << ans << endl;
}
