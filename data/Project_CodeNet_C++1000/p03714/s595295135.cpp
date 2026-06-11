#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  long long a[3*N], sum = 0, answer = LLONG_MIN;
  map<int,long long> b, c;
  multiset<int> d;
  for (int i = 0; i < 3*N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < N; i++) {
    sum += a[i];
    d.insert(a[i]);
  }
  b[N-1] = sum;
  for (int i = N; i < 2*N; i++) {
    if (a[i] > *d.begin()) {
      sum -= *d.begin();
      sum += a[i];
      d.erase(d.find(*d.begin()));
      d.insert(a[i]);
    }
    b[i] = sum;
  }
  d.clear();
  sum = 0;
  for (int i = 2*N; i < 3*N; i++) {
    sum += a[i];
    d.insert(a[i]);
  }
  c[2*N] = sum;
  for (int i = 2*N-1; i >= N; i--) {
    if (a[i] < *d.rbegin()) {
      sum -= *d.rbegin();
      sum += a[i];
      d.erase(d.find(*d.rbegin()));
      d.insert(a[i]);
    }
    c[i] = sum;
  }
  for (int i = N-1; i < 2*N; i++) {
    answer = max(answer,b[i]-c[i+1]);
  }
  cout << answer;
}