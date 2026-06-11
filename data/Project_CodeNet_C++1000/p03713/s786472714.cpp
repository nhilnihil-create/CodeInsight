#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int H, W;
  cin >> H >> W;
  long long int ans = 1000000000000;
  for (long long int i = 1; i < H; i++) {
    long long int A = i * W;
    long long int B = (H - i) * (W / 2);
    long long int C = (H - i) * W - B;
    long long int Smax = max(max(A, B), C);
    long long int Smin = min(min(A, B), C);
    ans = min(ans, Smax - Smin);
    B = (H - i) / 2 * W ;
    C = (H - i) * W - B;
    Smax = max(max(A, B), C);
    Smin = min(min(A, B), C);
    ans = min(ans, Smax - Smin);
  }
  swap(H, W);
  for (long long int i = 1; i < H; i++) {
    long long int A = i * W;
    long long int B = (H - i) * (W / 2);
    long long int C = (H - i) * W - B;
    long long int Smax = max(max(A, B), C);
    long long int Smin = min(min(A, B), C);
    ans = min(ans, Smax - Smin);
    B = (H - i) / 2 * W;
    C = (H - i) * W - B;
    Smax = max(max(A, B), C);
    Smin = min(min(A, B), C);
    ans = min(ans, Smax - Smin);
  }
  cout << ans << endl;
}