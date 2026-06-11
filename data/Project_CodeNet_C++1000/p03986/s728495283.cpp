#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  string X;
  cin >> X;
  int N = X.size();
  int count = 0;
  int answer = N;
  for (int i = 1; i < N; ++i) {
    // cout << X.substr(i - 1) << ": count=" << count << " answer=" << answer
    //<< endl;
    if (X[i - 1] == 'T' && X[i] == 'S') {
      count = 0;
    } else if (X[i - 1] == 'S' && X[i] == 'T') {
      X[i] = X[i - count];
      answer -= 2;
      count--;
    } else if (X[i - 1] == 'S') {
      count++;
    }
  }
  cout << answer << endl;
  return 0;
}