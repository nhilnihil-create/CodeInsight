#include <iostream>
using namespace std;

int main() {
  long long A, B, C;
  cin >> A >> B >> C;
  long long res = 1000000000;
  for (long long i = 0; i < 10000000; i++){
    if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1){
      res = i;
      break;
    }
    long long A_ = (B + C) / 2;
    long long B_ = (A + C) / 2;
    long long C_ = (A + B) / 2;
    A = A_;
    B = B_;
    C = C_;
  }
  if (res != 1000000000) cout << res << endl;
  else cout << -1 << endl;
}