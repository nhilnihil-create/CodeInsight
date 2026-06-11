#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>

typedef long long ll;
const double PI = acos(-1);

bool check(std::vector< ll >& vh, ll A, ll B, ll max_cnt)
{
  ll cnt = 0;
  std::vector< ll >::iterator it;
  for (it = vh.begin(); it != vh.end(); it++) {
    cnt += std::max(0LL, (*it - B * max_cnt + A - B - 1) / (A - B));
  }

  bool judge = false;
  if (cnt <= max_cnt) {
    judge = true;
  }

  //std::cout << max_cnt << " " << judge << std::endl;
  return judge;
}

int main(int argc, char* argv[])
{
  ll N, A, B;
  std::cin >> N >> A >> B;

  ll left  = 0;
  ll right = 1e9+1;

  std::vector< ll > vh(N, 0);
  for (ll i = 0; i < N; i++) {
    std::cin >> vh[i];
  }

  while (right - left > 1) {
    ll mid = (left + right) / 2;
    if (check(vh, A, B, mid)) {
      right = mid;
    } else {
      left = mid;
    }
  }

  std::cout << right << std::endl;
  
  return 0;
}
