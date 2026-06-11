#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;



int main() {

//  int N = 2;
//  long long nums[] = {3, 1, 4, 1, 5, 9};
//  int N = 1;
//  long long nums[] = {1, 2, 3};
//  int N = 3;
//  long long nums[] = {8, 2, 2, 7, 4, 6, 5, 3, 8};

  int N;
  cin >> N;
  long long nums[N*3];
  for (int i = 0; i < N*3; ++i) {
    cin >> nums[i];
  }


  auto cmp_descending = [](long long a, long long b) { return a > b; };
  auto cmp_ascending = [](long long a, long long b) { return a < b; };
  vector<long long> front_sums, back_sums;

  //
  long long front_sum = 0;
  priority_queue<long long, vector<long long>, function<bool(long long, long long)>> front_queue(cmp_descending);
  for (int i = 0; i < N; ++i) {
    front_queue.push(nums[i]);
    front_sum += nums[i];
  }
  front_sums.push_back(front_sum);

  //
  long long back_sum = 0;
  priority_queue<long long, vector<long long>, function<bool(long long, long long)>> back_queue(cmp_ascending);
  for (int i = 2 * N; i < 3 * N; ++i) {
    back_queue.push(nums[i]);
    back_sum += nums[i];
  }
  back_sums.push_back(back_sum);

  //
  for (int i = N; i < 2 * N; ++i) {
    front_queue.push(nums[i]);
    int remove = front_queue.top();
    front_queue.pop();
    front_sum += (nums[i] - remove);
    front_sums.push_back(front_sum);
  }


  //
  for (int i = 2 * N - 1; i >= N; i--) {
    back_queue.push(nums[i]);
    int remove = back_queue.top();
    back_queue.pop();
    back_sum += (nums[i] - remove);
    back_sums.push_back(back_sum);
//    cout << "remove " << remove << endl;
  }
  reverse(back_sums.begin(), back_sums.end());


  long long max_sum = -50000000000000000;
  for (int i = 0; i < front_sums.size(); ++i) {
//    cout << front_sums[i] << " " << back_sums[i] << front_sums[i] - back_sums[i] << endl;
    max_sum = max(max_sum, front_sums[i] - back_sums[i]);
//    cout << "front_sums " << front_sums[i] << endl;
//    cout << "back_sums " << back_sums[i] << endl;
//    cout << " " << (front_sums[i] - back_sums[i]) << endl;
  }

  cout << max_sum << endl;
}
