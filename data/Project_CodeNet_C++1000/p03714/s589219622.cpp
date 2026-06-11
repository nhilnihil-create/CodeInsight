#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

int main(){
  int N;
  std::cin >> N;

  std::vector<int> a_arr(3*N);
  for(int i = 0; i < 3*N; i++) std::cin >> a_arr[i];

  std::priority_queue<int, std::vector<int>, std::function<bool(int,int)>> left([&](int l, int r){return a_arr[l]>a_arr[r];}), right([&](int l, int r){return a_arr[l]>a_arr[r];});
  for(int i = 0; i < N; i++) left.push(i);

  std::vector<int> right_index(2*N);
  std::vector<int> remove_arr(3*N);
  for(int i = N; i < 3*N; i++) right_index[i-N] = i;
  std::sort(right_index.begin(), right_index.end(), [&](int l, int r){return a_arr[l]>a_arr[r];});
  for(int i = 0; i < N; i++){
    right.push(right_index[i]);
    remove_arr[right_index[i]] = 1;
  }
  long long sum_left = 0, sum_right = 0;
  for(int i = 0; i < N; i++) sum_left += a_arr[i];
  for(int i = N; i < 2*N; i++) sum_right += a_arr[right_index[i]];

  long long max_sum_diff = sum_left-sum_right;
  for(int th = N; th < 2*N; th++){
    if(remove_arr[th] == 0){
      int ri;
      while(true){
        ri = right.top();
        right.pop();
        if(ri > th) break;
      }
      remove_arr[ri] = 0;
      sum_right += a_arr[ri] - a_arr[th];
    }
    left.push(th);
    int li = left.top();
    left.pop();
    sum_left += a_arr[th] - a_arr[li];
    max_sum_diff = std::max(max_sum_diff, sum_left-sum_right);
  }

  std::cout << max_sum_diff << std::endl;

  return 0;
}

