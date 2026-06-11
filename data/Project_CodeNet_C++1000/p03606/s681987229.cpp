#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, A = 0, B = 0, sum = 0;
  cin >> N;
  rep(i, N){
    cin >> A >> B;
    sum = sum + B - A + 1;
  }
  cout << sum << endl;
  return 0;
}
