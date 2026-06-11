#include <iostream>
#include <string>
#include <vector>

typedef long long ll;
const ll MAX_NUM = 1e9;

ll N, A, B;

bool is_ok(std::vector< ll >& vh, ll limit)
{
  std::vector< ll >::iterator it;

  ll cnt = 0;
  for (it = vh.begin(); it != vh.end(); it++) {
    cnt += std::max(0LL, (*it - limit * B + A - B - 1) / (A - B));
  }

  bool judge = false;
  if (cnt <= limit) {
    judge = true;
  }
  return judge;
}

int main(int argc, char* argv[])
{
  std::cin >> N >> A >> B;
  std::vector< ll > vh(N, 0);

  for (ll i = 0; i < N; i++) {
    std::cin >> vh[i];
  }

  ll left = 0;
  ll right = MAX_NUM;
  while (right - left > 1) {
    ll mid = (left + right) / 2;
    if (is_ok(vh, mid)) {
      right = mid;
    } else {
      left  = mid;
    }
  }

  std::cout << right << std::endl;
  
  return 0;
}
