#include <algorithm>
#include <iostream>
#include <vector>

int rate2step(int r)
{
  if(3200 <= r) {
    r = 3200;
  }
  return r / 400;
}

int main()
{
  int N;
  constexpr int N_STEP = 9;
  std::vector<int> num(N_STEP);
  std::cin >> N;
  for(int i=0; i<N; i++) {
    int rate;
    std::cin >> rate;
    num[rate2step(rate)]++;
  }

  int fixed_colors = 0;
  for(int i=0; i<N_STEP-1; i++) {
    fixed_colors += num[i] > 0 ? 1 : 0;
  }

// over 3200 member selects fixed_colors
  int min = fixed_colors;
  if(min == 0 && num[N_STEP-1] > 0) {
    min = 1;
  }
  int max = fixed_colors + num[N_STEP-1];

  std::cout << min << " " << max << std::endl;

  return 0;
}
