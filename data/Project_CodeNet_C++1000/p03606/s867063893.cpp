#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N,S;
  cin >> N;
  rep(i,N) {
    int l_i,r_i;
    cin >> l_i >> r_i;
    S += r_i - l_i + 1;
  }
  cout << S << endl;
}