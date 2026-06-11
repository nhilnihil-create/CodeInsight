#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <sstream>
#include <unordered_set>
#include <future>
using namespace std;



int main()
{
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  std::vector<int> v(3 * n);

  for (auto& el : v) {
    cin >> el;
  }
  std::sort(v.begin(), v.end());
  int64_t sum = 0;
  for (int i = 3 * n - 2, j = 0; j < n; j++, i -= 2) {
    sum += v[i];
  }
  cout << sum << endl;

}