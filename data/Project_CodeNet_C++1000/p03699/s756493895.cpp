#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N, s{}, m{100};
  cin >> N;
  while(cin >> N) {
    s += N;
    if (N % 10) m = min(m,N);
  }
  if (m==100) s = 0;
  else if (s % 10 == 0) s -= m;
  cout << s << endl;
}
