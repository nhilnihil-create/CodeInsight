#include<iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  int A[N];
  for (int i = 0; i < N; i++) cin >> A[i];

  int groups = 1;
  int B[3] = {0};
  for (int i = 2; i < N;) {
    int a=A[i-2], b=A[i-1], c=A[i];
    if (a == b) {
      i++;
      continue;
    }
    if (b == c) {
      swap(A[i-2], A[i-1]);
      i++;
      continue;
    }
    bool cond1 = a <= b && b <= c;
    bool cond2 = a >= b && b >= c;
    if (cond1 || cond2) i++;
    else {
      groups++;
      i += 2;
    }
  }

  cout << groups << endl;

  return 0;
}
