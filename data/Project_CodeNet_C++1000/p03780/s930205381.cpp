#include<algorithm>
#include<iostream>
#include<vector>

bool is_no_need(int ex, std::vector<int>& a, int K){
  int n = (int)a.size();
  std::vector<std::vector<int>> no_good(n + 1, std::vector<int>(K, 0));
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < K; j++){
      if(i == ex){
        no_good[i + 1][j] = no_good[i][j];
        continue;
      }
      
      if(j + a[i] < K) no_good[i + 1][j + a[i]] = std::max(no_good[i][j] + a[i], no_good[i + 1][j + a[i]]);
      no_good[i + 1][j] = std::max(no_good[i][j], no_good[i + 1][j]);
    }
  }
  
  return no_good[n][K - 1] + a[ex] < K;
}

int count_no_need(std::vector<int>& a, int K){
  int n = (int)a.size();
  
  int need = n;
  int no_need = -1;
  while(need - no_need > 1){
    int mid = (need + no_need) / 2;
    (is_no_need(mid, a, K) ? no_need : need) = mid;
  }
  
  return no_need + 1;
}

int main(){
  int N, K;
  std::cin >> N >> K;
  
  std::vector<int> a(N);
  for(int i = 0; i < N; i++) std::cin >> a[i];
  std::sort(a.begin(), a.end());
  
  std::cout << count_no_need(a, K) << std::endl;
  
  return 0;
}