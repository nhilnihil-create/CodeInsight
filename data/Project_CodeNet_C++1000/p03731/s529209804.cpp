#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long long T;
  cin >> N >> T;
  long long sum = T;
  vector<long long> t(N);
  for(int i = 0 ; i < N; i++) {
    cin >> t.at(i);
  }
  vector<long long> s(N-1);
  for(int i = 0 ; i < N-1; i++) {
    s.at(i) = t.at(i+1) - t.at(i);
  }
  for(int i = 0 ; i < N-1; i++) {
    sum += min(T,s.at(i));
  }
  cout << sum;
}

