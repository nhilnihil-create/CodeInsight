#include <iostream>
using namespace std;

int main() {
  long long A, B, C;
  cin >> A >> B >> C;
  
  long long min_ = 1000000000000000000;
  if (A % 2 == 0) min_ = 0;
  else min_ = min(min_, B * C);
  if (B % 2 == 0) min_ = 0;
  else min_ = min(min_, A * C);
  if (C % 2 == 0) min_ = 0;
  else min_ = min(min_, A * B);
  
  cout << min_ << endl;
}