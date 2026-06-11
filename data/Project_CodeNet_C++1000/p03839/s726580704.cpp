#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
#include <set>
#include <climits>
#include <map>
#include <cmath>
#include <deque>
#include <numeric>

using namespace std;

long long a[100000];
long long K_sums[100000];
long long cum_sum_positive[100000];
int main(){
  int N;
  int K;
  cin >> N >> K;

  for(int i = 0; i < N; i++){
    cin >> a[i];
  }
  //long long sum_a = accumulate(a, a + N, (long long) 0);

  for(int i = 0; i < K; i++){
    K_sums[0] += a[i];
  }
  for(int i = 1; i < N - K + 1; i++){
    K_sums[i] = K_sums[i - 1] - a[i - 1] + a[i + K - 1];
  }

  if(a[0] > 0){
    cum_sum_positive[0] = a[0];
  } else {
    cum_sum_positive[0] = 0;
  }
  for(int i = 1; i < N; i++){
    if(a[i] > 0){
      cum_sum_positive[i] = cum_sum_positive[i - 1] + a[i];
    } else {
      cum_sum_positive[i] = cum_sum_positive[i - 1];
    }
  }

  long long ans = 0;
  for(int i = 0; i < N - K + 1; i++){
    long long tmp_ans = 0;
    long long left_positive_sum;
    if(i > 0){
      left_positive_sum = cum_sum_positive[i - 1];
    } else {
      left_positive_sum = 0;
    }
    long long right_positive_sum = 0;
    if(i < N - K){
      right_positive_sum = cum_sum_positive[N - 1] - cum_sum_positive[K + i - 1];
    } else {
      right_positive_sum = 0;
    }

    tmp_ans = left_positive_sum + right_positive_sum + max((long long) 0, K_sums[i]);
    ans = max(ans, tmp_ans);
  }
  cout << ans << endl;
  return 0;
}