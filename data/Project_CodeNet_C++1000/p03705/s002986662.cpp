#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  if(A > B) {
    cout << 0 << endl;
  }
  else if(N == 2) {
    cout << 1 << endl;
  }
  else if(N == 1) {
    if(A == B) {
      cout << 1 << endl;
    }
    else {
      cout << 0 << endl;
    }
  }
  else {
    cout << (B - A) * (N - 2) + 1 << endl;
  }
}
