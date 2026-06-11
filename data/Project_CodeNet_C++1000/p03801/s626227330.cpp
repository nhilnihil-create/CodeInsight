#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<cstdint>

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N; std::cin >> N;
  std::vector<int64_t> ans(N, 0);
  std::map<int,std::pair<int,int64_t>> m;
  for(int i = 0; i < N; ++i) {
    int a; std::cin >> a;
    if(m.count(a)>0) ++m[a].second;
    else m[a] = std::make_pair(i, 1);
  }
  while(m.size() > 1) {
    auto it = m.end();
    --it;
    auto p = it->second;
    int64_t a = it->first;
    m.erase(it);
    ans[p.first] += (a - m.rbegin()->first)*p.second;
    auto& np = m.rbegin()->second;
    np.first = std::min(np.first, p.first);
    np.second += p.second;
  }
  int a = m.begin()->first;
  auto p = m.begin()->second;
  ans[p.first] += a*p.second;
  for(int i = 0; i < N; ++i) std::cout << ans[i] << "\n";

  return 0;
}
