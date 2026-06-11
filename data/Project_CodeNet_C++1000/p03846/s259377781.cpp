#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("../data.txt");

long long n, x, power;
long long v[100005];
bool ok = 1;

long long toPow(long long a, long long b) {
  long long ans = 1;
  while(b) {
    if (b%2) ans = ((1LL * ans * a) % 1000000007);
    a = ((1LL * a * a) % 1000000007);
    b /= 2;
  }
  return ans;
}

int main() {

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v[x]++;
  }

  if (n%2 && v[0] != 1) {
     ok = 0;
  }

  for (int i = 1; i < n && ok; i++) {
    if (v[i] == 1) {
       ok = 0;
    }
    if (v[i] == 2) power++;
  }

  if (!ok) cout << 0;
  else cout << (long long) toPow(2, power);

  return 0;
}
