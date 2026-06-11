#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <map>

using namespace std;

struct Data {
  int id, a;
  Data() {}
  Data(int id, int a): id(id), a(a) {}
};

int uid(Data &d, int to) {
  return 2*d.a + (to%2);
}

int main() {
  int n;
  cin >> n;
  vector<Data> la;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    la.emplace_back(i, a);
  }
  sort(
    la.begin(),
    la.end(),
    [](const Data& lhs, const Data& rhs) { return lhs.a < rhs.a; }
  );
  map<int, int> count;
  for (int i = 0; i < n; ++i) { 
    Data &d = la[i];
    count[uid(d, i)] += 1;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) { 
    Data &d = la[i];
    int id = uid(d, d.id);
    if (count.find(id) == count.end()) {
      ++ans;
      continue;
    }
    if (count[id] == 0) {
      ++ans;
      continue;
    }
    // cerr << id << " " << count[id] << endl;
    --count[id];
  }
  cout << ans/2 << endl;

  return 0;
}
