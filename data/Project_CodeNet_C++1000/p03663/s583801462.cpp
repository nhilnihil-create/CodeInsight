#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

void ans(int64 n) {
  cout << "! " << n << endl;
  exit(0);
}

bool ask(int64 n) {
  cout << "? " << n << endl;
  char c;
  cin >> c;
  return c == 'Y';
}

int main() {

  int64 mul = 10;
  int64 low = -1, high = -1;
  for(int i = 2; i <= 10; i++) {
    if(!ask(mul)) {
      low = mul / 10;
      high = mul;
      break;
    }
    mul *= 10;
  }
  if(low == -1) {
    mul = 10;
    for(int i = 1; i <= 10; i++) {
      if(ask(mul - 1)) ans(mul / 10);
      mul *= 10;
    }
  }

  while(high - low > 1) {
    int64 mid = (low + high) / 2;
    if(ask(mid * 10)) high = mid;
    else low = mid;
  }
  ans(high);
}
