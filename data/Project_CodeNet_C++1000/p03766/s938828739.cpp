// you can use includes, for example:
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <unordered_map>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include <set>
#include <cassert>
#include <map>

using namespace std;

constexpr int64_t kMod = 1e9 + 7;
constexpr int64_t kMaxN = 1e6 + 1;

int64_t din[kMaxN][2];
std::vector<int> gen;
int total = 0;

void Print() {
  for (auto& el : gen) {
    cout << el << " ";
  }
  cout << endl;
}

bool Check(int n) {

  auto check_seg = [&](int l, int r) {
    int cur = gen[l];
    for (int i = l; i <= r; i++) {
      if (gen[i] != cur) {
        return false;
      }
    }
    return true;
  };

  for (int i = 0; i < n - 1; i++) {
    if (!check_seg(i + 1, min(i + gen[i], n - 1))) {
      return false;
    }
  }
  Print();
  return true;
}

void Gen(int i, int n) {
  if (i == n) {
    total += Check(n);
  } else {
    for (int j = 1; j <= n; j++) {
      gen.push_back(j);
      Gen(i + 1, n);
      gen.pop_back();
    }
  }
}

void Test(int n) {
  total = 0;
  Gen(0, n);
  cout << "Correct answer " << total << endl;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
//  Test(n);

  din[1][0] = 1;
  din[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    din[i][0] = din[i - 1][0];
    din[i][0] += din[i - 2][1];
    din[i][0] %= kMod;
    din[i][1] = (din[i - 1][1] + din[i - 1][0]) % kMod;
  }


  auto calc = [&](int rem) {
    if (rem == 0) {
      return static_cast<int64_t>(1LL);
    }
    if (rem == 1) {
      return static_cast<int64_t>(n - 1LL);
    }
    int64_t sum = 0;
    sum += (n - 1) * 1ll * (n - 1);
    sum += n - (rem) + 1;
    sum %= kMod;
    return static_cast<int64_t>(sum);
  };

//  cout << "Din " <<  din[4] << endl;


  int64_t ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += ((i == 0 ? 1LL : din[i][0]) * 1ll * calc(n - i));
//    cout << i << " " << ans << endl;
    ans %= kMod;
  }
  cout << ans << endl;
}
