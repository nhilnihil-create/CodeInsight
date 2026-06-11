#include <bits/stdc++.h>
using namespace std;

long long get_operation_count(vector<long long> &a, int n,
                              bool is_start_negative) {
  long long a_sum = 0;
  long long diff_sum = 0;
  long long operation_count = 0;

  for (int i = 0; i < n; i++) {
    a_sum += a[i];
    long long sum = a_sum + diff_sum;
    int is_positive = i % 2 == 0;
    if (is_start_negative) is_positive = !is_positive;

    if (is_positive && sum <= 0) {
      long long diff_abs = abs(1 - sum);
      operation_count += diff_abs;
      diff_sum += diff_abs;
    } else if (!is_positive && 0 <= sum) {
      long long diff_abs = abs(-1 - sum);
      operation_count += diff_abs;
      diff_sum -= diff_abs;
    }
  }

  if (a_sum + diff_sum == 0) operation_count++;
  return operation_count;
}

int main() {
  int n;
  cin >> n;

  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  long long positive_count = get_operation_count(a, n, true);
  long long negative_count = get_operation_count(a, n, false);

  cout << min(negative_count, positive_count) << endl;
}
