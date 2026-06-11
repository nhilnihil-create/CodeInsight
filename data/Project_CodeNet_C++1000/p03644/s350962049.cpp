#include <bits/stdc++.h>
using namespace std;

int divide_by_2_count(int N) {
  int count = 0;
  while (true) {
    if (N % 2 == 0) {
      count++;
      N /= 2;
    } else {
      break;
    }
  }
  return count;
}

int main() {
  int N;
  cin >> N;

  int max_divide_count = 0;
  int max_divide_num = N;
  for (int i = N; i >= 1; i--) {
    int count = divide_by_2_count(i);
    if (count > max_divide_count) {
      max_divide_count = count;
      max_divide_num = i;
    }
  }

  cout << max_divide_num << endl;
}