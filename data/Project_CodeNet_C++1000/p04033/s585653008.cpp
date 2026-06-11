#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
  ll A, B;
  cin >> A >> B;
  if(A <= 0 && 0 <= B) {
    cout << "Zero" << endl;
  }
  else if(A > 0) {
    cout << "Positive" << endl;
  }
  else {
    if((B - A) % 2 == 0) {
      cout << "Negative" << endl;
    }
    else {
      cout << "Positive" << endl;
    }
  }
}