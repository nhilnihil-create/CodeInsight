#include <bits/stdc++.h>
using namespace std;
int main() {
  int X, A, B;
  cin >> X >> A >> B;
  if(A >= B) {
    cout << "delicious" << endl;
  }
  else if((X + A) >= B) {
    cout << "safe" << endl;
  }
  else {
    cout << "dangerous" << endl;
  }
}
