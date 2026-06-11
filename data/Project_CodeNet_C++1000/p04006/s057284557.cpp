#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
#include <set>
#include <climits>
#include <map>

using namespace std;

long long a[2000];
long long min_a_cost[2000];
int main(){
  int N;
  long long x;
  cin >> N >> x;
  for(int i = 0; i < N; i++){
    cin >> a[i];
    min_a_cost[i] = a[i];
  }

  long long ans = LLONG_MAX;
  for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        min_a_cost[j] = min(min_a_cost[j], a[((j - i) % N + N) % N]);
      }
      long long tmp_ans = accumulate(min_a_cost, min_a_cost + N, (long long) 0) + (long long) i * x;
      ans = min(ans, tmp_ans);
  }
  cout << ans << endl;
  return 0;
}
