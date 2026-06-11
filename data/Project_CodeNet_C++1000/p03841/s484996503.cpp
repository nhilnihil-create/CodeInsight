#include<iostream>
#include<vector>
#include<queue>
#include<numeric>
#include<algorithm>

bool solve(){
  int n;
  std::cin  >> n;
  std::vector<int> x(n);
  for (int &e : x) {
    std::cin >> e;
    e -= 1;
  }
  std::vector<int> ans(n * n, n);
  for (int i = 0; i != n; i += 1) {
    ans[x[i]] = i;
  }
  std::queue<int> task, rem;
  {
    std::vector<int> idx(n);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(),
      [&x](int l, int r){return x[l] < x[r];});
    for (const int i : idx) {
      for (int j = 0; j != i; j += 1) {
        task.push(i);
      }
      for (int j = i; j != n - 1; j += 1) {
        rem.push(i);
      }
    }
  }
  std::vector<int> count(n, 0);
  for (int i = 0; i != n * n; i += 1) {
    if (ans[i] != n) {
      if(count[ans[i]] != ans[i]) return false;
    }
    else if (!task.empty()) {
      ans[i] = task.front();
      task.pop();
    } else {
      ans[i] = rem.front();
      rem.pop();
    }
    count[ans[i]] += 1;
  }
  std::cout << "Yes\n";
  for (int i = 0; i != n * n; i += 1) {
    if (i != 0) std::cout << " ";
    std::cout << ans[i] + 1;
  }
  std::cout << "\n";
  return true;
}


int main() {
  if (!solve()) {
    std::cout << "No\n";
  }
}