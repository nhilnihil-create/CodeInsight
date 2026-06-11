#pragma GCC diagnostic ignored "-Wsign-compare"

#include <iostream>
#include <string>
using namespace std;

constexpr int INF = 100100100;
string str;

inline int procedure(const char &target) {
  int ret = 0;
  string copy = str;

  while (1) {
    bool consists_of_a_single_character = true;
    for (int idx = 1; idx < copy.size(); idx++) {
      if (copy[idx] != copy[0]) {
        consists_of_a_single_character = false;
        break;
      }
    }
    if (consists_of_a_single_character) break;

    ret++;

    string new_str(copy.size() - 1, '.');
    for (int i = 0; i < copy.size() - 1; i++) {
      if (copy[i] == target || copy[i+1] == target) new_str[i] = target;
      else new_str[i] = copy[i];
    }

    copy = new_str;
  }

  return ret;
}

int main() {
  cin >> str;
  int ans = INF;

  for (char target = 'a'; target <= 'z'; target++) {
    int tmp = procedure(target);
    if (ans > tmp) ans = tmp;
  }

  cout << ans << endl;
  return 0;
}
