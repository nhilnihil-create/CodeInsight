#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n;
  cin >> n;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  list<ll> ans_list;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      ans_list.push_front(a[i]);
    } else {
      ans_list.push_back(a[i]);
    }
  }

  if (n % 2 == 0) {
    auto itr = ans_list.rbegin();
    while (itr != ans_list.rend()) {
      printf("%ld ", *itr++);
    }
  } else {
    auto itr = ans_list.begin();
    while (itr != ans_list.end()) {
      printf("%ld ", *itr++);
    }
  }
  printf("\n");
}
