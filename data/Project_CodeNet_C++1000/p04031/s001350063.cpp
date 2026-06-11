#include <iostream>
#include <vector>

using namespace std;

template<class T>
T square(const T &x) { return x * x; }

template<class T>
bool chmin(T &a, const T &b) { return b < a && (a = b, 1); }

const int INF = 2147483647;

int main() {
  int N;
  cin >> N;

  vector<int> a(N);
  for (int &i : a) cin >> i;

  int res = INF;
  for (int i = -100; i <= 100; ++i) {
    int sum = 0;
    for (const int &x : a) sum += square(x - i);
    chmin(res, sum);
  }

  cout << res << endl;
}
