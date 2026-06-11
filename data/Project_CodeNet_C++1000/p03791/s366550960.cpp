#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> x_array(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> x_array[i];
  }

  const long long mod = 1000000000 + 7;

  int zone = 0;
  long long ans = 1;
  long long zanki = 0;
  long long vacant = 0;

  for (const int x : x_array) {
    zanki += 1;

    int cur_zone = x / 2;
    if (x % 2 == 1) {
      cur_zone += 1;
    }

    if (zone < cur_zone) {
      vacant += (cur_zone - zone) - 1;
      zone = cur_zone;
    } else {
      if (vacant > 0) {
        vacant -= 1;
      } else {
        ans = (ans * zanki) % mod;
        zanki -= 1;
      }
    }
  }

  for (long long i = zanki; i >= 2; --i) {
    ans = (ans * i) % mod;
  }

  std::cout << ans << std::endl;
  return 0;
}
