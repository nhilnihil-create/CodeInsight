#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

template <typename Container, class T>
bool _contains(const Container& c, T v)
{
  return std::find(c.begin(), c.end(), v) != c.end();
}

/**
 * check n has ng digits.
 * \param n target value
 * \param ngs ng digits
 * return true: contain NG digits, false: not contain.
 */
bool contains(int n, const std::vector<int>& ngs)
{
  std::string sn = std::to_string(n);
  std::set<int> digits;

  for(auto d : sn) {
    if(!_contains(digits, d)) {
      digits.insert(d - '0');
    }
  }

  bool contains = false;
  for(auto d : ngs) {
    if(_contains(digits, d)) {
      //  std::cout << "digits contains " << d << std::endl;
      contains = true;
      break;
    }
  }

  return contains;
}

int main()
{
  int N, K;
  std::cin >> N >> K;
  std::vector<int> D(K);
  for(int i = 0; i < K; i++) {
    std::cin >> D[i];
  }

  // check N * 1
  int total = 0;
  for(total = N; ;total++) {
    //  if(i % 1000 == 0) {
    //  std::cout << i << std::endl;
    //  }
    if(!contains(total, D)) {
      break;
    }
  }

  std::cout << std::fixed << total << std::endl;

  return 0;
}
