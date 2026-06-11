#include<iostream>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

bool is_even(int n) {
  return n % 2 == 0;
}

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  bool inf = false;
  int ans = 0;
  while (1) {
    if (A == B && B == C) {
      if (!is_even(A)) break;
      inf = true;
      break;
    }
    if (!is_even(A) || !is_even(B) || !is_even(C)) break;
    int tmp_a = 0, tmp_b = 0, tmp_c = 0;
    tmp_a += B / 2;
    tmp_a += C / 2;
    tmp_b += A / 2;
    tmp_b += C / 2;
    tmp_c += A / 2;
    tmp_c += B / 2;
    A = tmp_a, B = tmp_b, C = tmp_c;
    ++ans;
  }

  if (inf) cout << "-1" << endl;
  else cout << ans << endl;

  return 0;
}
