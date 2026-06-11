#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("data.txt");

int n, r1, r2;
long long v1, v2, aux;

long long f(long long a, long long x) {
  long long ans = a/x;
  if (a % x) ans++;
  return ans;
}

int main() {
  cin >> n;
  cin >> v1 >> v2;
  n--;

  while (n--) {
    cin >> r1 >> r2;
    aux = max(f(v1, r1), f(v2, r2));
    v1 = r1*aux;
    v2 = r2*aux;
  }
  cout << v1 + v2;
  return 0;
}
