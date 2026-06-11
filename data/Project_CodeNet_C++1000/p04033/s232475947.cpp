#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  ll A, B;
  cin >> A >> B;
  if(A > 0) {
    cout << "Positive" << endl;
  }
  else if(B < 0) {
    if((B - A + 1) % 2 == 0) {
      cout << "Positive" << endl;
    }
    else {
      cout << "Negative" << endl;
    }
  }
  else {
    cout << "Zero" << endl;
  }
}