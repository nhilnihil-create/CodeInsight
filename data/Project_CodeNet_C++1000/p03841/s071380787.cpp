#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N; std::cin >> N;
  std::vector<std::pair<int,int>> ps(N);
  for(int i = 0; i < N; ++i) {
    std::cin >> ps[i].first;
    --ps[i].first;
    ps[i].second = i+1;
  }
  std::sort(ps.begin(), ps.end());
  std::vector<int> ans(N*N, -1);
  int t = 0;
  for(auto const& p: ps) {
    int x = p.first, i = p.second;
    ans[x] = i;
    for(int c = 0; c < i-1; ++c) {
      while(t < x && ans[t] != -1) ++t;
      if(t >= x) fin("No");
      ans[t] = i;
      ++t;
    }
  }
  t = N*N-1;
  for(auto it = ps.rbegin(); it != ps.rend(); ++it) {
    int x = it->first, i = it->second;
    for(int c = 0; c < N-i; ++c) {
      while(t > x && ans[t] != -1) --t;
      if(t <= x) fin("No");
      ans[t] = i;
      --t;
    }
  }
  std::cout << "Yes\n";
  for(int i = 0; i < N*N-1; ++i) std::cout << ans[i] << " ";
  std::cout << ans[N*N-1] << std::endl;
  return 0;
}
