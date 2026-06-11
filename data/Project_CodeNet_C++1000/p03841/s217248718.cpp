#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

struct Element {
  int index;
  int value;
};

constexpr int DEBUG = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<Element> elements;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x--;
    elements.push_back(Element({x, i + 1}));
  }
  sort(elements.begin(), elements.end(), [](Element e1, Element e2) {
    return e1.index < e2.index;
  });
  // for (const auto& e : elements) {
  //   cout << e.index << " " << e.value << endl;
  // }

  
  vector<int> output(n * n, -1);
  int current = 0;
  auto push_fn = [&](int x) {
    while (current < n * n && output[current] >= 0) current++;
    output[current] = x;
    while (current < n * n && output[current] >= 0) current++;
  };
  for (const auto& e : elements) {
    for (int i = 1; i <= e.value - 1; i++) {
      push_fn(e.value);
    }
    if (current > e.index) {
      if (DEBUG) cout << "DEBUG No 1" << endl;
      cout << "No" << endl;
      return 0;
    }
    output[e.index] = e.value;
    while (current < n * n && output[current] >= 0) current++;
  }
  for (const auto& e : elements) {
    if (e.value < n && current < e.index) {
      if (DEBUG) cout << e.value << endl;
      if (DEBUG) cout << "DEBUG No 2" << endl;
      cout << "No" << endl;
      return 0;
    }
    for (int j = 1; j <= n - e.value; j++) {
      push_fn(e.value);
    }
  }
  cout << "Yes" << endl;
  for (int x : output) cout << x << " ";
  cout << endl;
}