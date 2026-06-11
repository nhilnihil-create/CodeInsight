#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
  ll A, B, C;
  cin >> A >> B >> C;
  if(A == B && A == C && A % 2 == 0) {
    cout << -1 << endl;
  }
  else {
    int count = 0;
    while(A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
      ll a = A, b = B, c = C;
      A = b / 2 + c / 2;
      B = c / 2 + a / 2;
      C = a / 2 + b / 2;
      count++;
    }
    cout << count << endl;
  }
}