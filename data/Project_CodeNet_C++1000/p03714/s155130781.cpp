#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <queue>
#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int MOD = 1000000007;

int main() {
  int N; cin >> N;
  int arr1[N]; rep(i, N) cin >> arr1[i];
  int arr2[N]; rep(i, N) cin >> arr2[i];
  int arr3[N]; rep(i, N) cin >> arr3[i];

  ll sum_1[N+1] = {} ; rep(i, N) sum_1[0] += arr1[i];
  ll sum_2[N+1] = {} ; rep(i, N) sum_2[0] += arr3[i];
  priority_queue<int, vector<int>, greater<int>> q1; rep(i, N) q1.push(arr1[i]);
  priority_queue<int, vector<int>, less<int>> q2; rep(i, N) q2.push(arr3[i]);

  rep(i, N) {
    sum_1[i+1] = sum_1[i] + arr2[i];
    q1.push(arr2[i]);
    sum_1[i+1] -= q1.top();
    q1.pop();
  }
  rep(i, N) {
    sum_2[i+1] = sum_2[i] + arr2[(N-1)-i];
    q2.push(arr2[(N-1)-i]);
    sum_2[i+1] -= q2.top();
    q2.pop();
  }

  ll result = -1 * LLINF;
  rep(i, N+1) result = max(result, sum_1[i]-sum_2[N-i]);
  cout << result << endl;
  return 0;
}