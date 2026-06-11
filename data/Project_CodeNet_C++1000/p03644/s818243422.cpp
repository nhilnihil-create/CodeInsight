#include <bits/stdc++.h>
#define rep(i, to) for (int i = 0; i < (to); ++i)
#define repf(i, from, to) for (int i = (from); i < (to); ++i)
#define unless(cond) if (!(cond))
using namespace std;
using ll = long long;
template <typename T>
using V = vector<T>;
template <typename T, typename U>
using P = pair<T, U>;

int count_two_factor(int num) {
  int count = 0;
  while(num % 2 == 0) {
    count++;
    num /= 2;
  }

  return count;
}

int main() {
  int n;

  cin >> n;

  int max_count = 0;
  int max_num = 1;
  repf(i, 1, n + 1) {
    int current_count = count_two_factor(i);

    if(current_count > max_count) {
      max_count = current_count;
      max_num = i;
    }
  }
  cout << max_num << endl;
}
