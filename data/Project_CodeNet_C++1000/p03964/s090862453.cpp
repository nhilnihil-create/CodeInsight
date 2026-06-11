#include<bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  long long A, T;
  cin >> T >> A;
  for (int i = 1; i < N; i ++) {
    long long t, a;
    cin >> t >> a;
    long long al = (T - 1) / t + 1;
    long long bt = (A - 1) / a + 1;
    long long k = max(al, bt);
    T = t * k;
    A = a * k;
  }
  cout << A + T << endl;
}