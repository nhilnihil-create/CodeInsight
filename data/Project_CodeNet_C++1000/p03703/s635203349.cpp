#include <bits/stdc++.h>
using namespace std;

class BIT {
  int size;
  vector<int> v;
public:
  BIT(int n)
    : size(n), v(n + 1) {
  }
  
  void add(int i, int del) {
    ++i;
    for (; i <= size; i += i & -i) {
      v[i] += del;
    }
  }
  
  int get(int i) {
    int sum = 0;
    for (; i > 0; i -= i & -i) {
      sum += v[i];
    }
    return sum;
  }
};

int n;
long a[200000];
long p[200001];
int main() {
  int k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] -= k;
  }
  partial_sum(a, a + n, p + 1);

  vector<int> ord(n + 1);
  iota(ord.begin(), ord.end(), 0);
  
  stable_sort(ord.begin(), ord.end(), [](int i, int j) {
    return p[i] < p[j];
  });
  
  BIT bit(n + 1);
  long cnt = 0;
  for (int i : ord) {
    cnt += bit.get(i);
    bit.add(i, 1);
  }
  cout << cnt << endl;
}