#include<iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  int a[N];
  for (int i = 0; i < N; i++) cin >> a[i];

  long long odd_cnt = 0, odd_sum_cnt = 0;
  for (int i = 0; i < N; i++) {
    odd_sum_cnt += a[i];
    if (i % 2 == 0) {
      while (0 <= odd_sum_cnt) {
        odd_sum_cnt--;
        odd_cnt++;
      }
    } else {
      while (odd_sum_cnt <= 0) {
        odd_sum_cnt++;
        odd_cnt++;
      }
    }
  }

  long long even_cnt = 0, even_sum_cnt = 0;
  for (int i = 0; i < N; i++) {
    even_sum_cnt += a[i];
    if (i % 2 == 0) {
      while (even_sum_cnt <= 0) {
        even_sum_cnt++;
        even_cnt++;
      }
    } else {
      while (0 <= even_sum_cnt) {
        even_sum_cnt--;
        even_cnt++;
      }
    }
  }

  cout << min(odd_cnt, even_cnt) << endl;
  return 0;
}
