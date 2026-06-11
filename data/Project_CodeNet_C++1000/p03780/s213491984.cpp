#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  int N,K;
  std::cin >> N >> K;

  std::vector<int> a_arr(N);
  for(int i = 0; i < N; i++) std::cin >> a_arr[i];
  std::sort(a_arr.begin(), a_arr.end());

  long long ans=N, sum=0;
  for(int i = N-1; i >= 0; i--){
    if(sum+a_arr[i] < K) sum += a_arr[i];
    else ans = i;
  }
  std::cout << ans << std::endl;

  return 0;
}

