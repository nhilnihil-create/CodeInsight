#include <vector>
#include <iostream>
#include <algorithm>

std::vector<std::vector<long long>> comb(int n) {
  std::vector<std::vector<long long>> v(n + 1,std::vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}

int main()
{
  int n, a, b;
  std::vector<long long> v;
  
  std::cin >> n >> a >> b;
  
  for(int i = 0; i < n; ++i) 
  {
    long long _v;
    std::cin >> _v;
    v.push_back(_v);
  }
  
  std::sort(v.begin(), v.end(), std::greater<long long>());
  long long s = 0;
  for(int i = 0; i < a; ++i)
  {
    s += v[i];
  }
  //std::cout << (double)s / a << "\n";
  printf("%.6lf\n", (double)s / a);
  
  int l, r;
  {
    auto range = std::equal_range(v.begin(), v.end(), v[a - 1], std::greater<long long>());
    l = std::distance(v.begin(), range.first);
    r = std::distance(v.begin(), range.second);
  }

  long long combination = 0;
  int nn = r - l;
  auto c = comb(nn);
  if(v[0] != v[a - 1])
  {
    int rr = a - l;
    combination += c[nn][rr];
  }
  else
  {
    int e = std::min(b, r);
    for(int aa = a; aa <= e; ++aa)
    {
      int rr = aa - l;
      combination += c[nn][rr];
    }
  }
  std::cout << combination;
} 