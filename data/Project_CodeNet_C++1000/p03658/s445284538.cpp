#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  int n, k, sum = 0, tmp;
  std::vector<int> l;
  std::cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    std::cin >> tmp;
    l.push_back(tmp);
  }

  std::sort(l.begin(), l.end(), std::greater<int>());
  std::vector<int>::iterator itr;
  itr = l.begin();
  for (int i = 0; i < k; i++)
  {
    sum += *itr;
    itr++;
  }

  std::cout << sum << std::endl;
  return 0;
}