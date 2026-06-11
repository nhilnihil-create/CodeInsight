#include <bits/stdc++.h>
using namespace std;

int main() { 
    long long n;
    cin >> n;
    long long A, B, out=1000000000000000, tmp=0,d_A=0, d_B=0;
    for (long long i = 1; i*i<=n; i++) {
      A = i;
      B = n / A;
      if (n != A * B) continue;
      string A_t = to_string(A);
      string B_t = to_string(B);
      d_A = A_t.length();
      d_B = B_t.length();
      tmp = max(d_A, d_B);
      out = min(out, tmp);
    }
    cout << out << endl;
    return 0;
}