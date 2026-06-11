#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef map<int, int> MII;
typedef vector<MII> VMII;
typedef pair<int, int> PII;
typedef priority_queue<PII> PQPII;
typedef vector<PQPII> VPQPII;

#define MP make_pair

int main() {
  int N, M;
  cin >> N >> M;

  VMII xss(M);
  VPQPII pqs(M);

  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    auto& m = xss[n%M];
    if (m.count(n)) {
      m[n]++;
    } else {
      m[n] = 1;
    }
  }

  for (int i = 0; i < M; i++) {
    auto& m = xss[i];
    for (auto it = m.begin(); it != m.end(); it++) {
      pqs[i].push(MP(it->second, it->first));
    }
  }

  VII yss(M);

  /*
  for (int i = 0; i < M; i++) {
    auto& m = pqs[i];
    cout << i;
    cout << ":";
    while (!m.empty()) {
      auto x = m.top(); m.pop();
      cout << x.first << "," << x.second;
      cout << "  ";
    }
    cout << endl;
  }
  */

  for (int i = 0; i < M; i++) {
    auto& m = pqs[i];
    VI a;
    VI b;
    while (!m.empty()) {
      auto x = m.top(); m.pop();
      auto num = x.first;
      auto v = x.second;
      for (int j = 0; j < num / 2 * 2; j++) {
        a.push_back(v);
      }
      if (num % 2) {
        b.push_back(v);
      }
    }
    yss[i].insert(yss[i].end(), a.begin(), a.end());
    yss[i].insert(yss[i].end(), b.begin(), b.end());
  }

  /*
  cout << endl;
  for (int i = 0; i < M; i++) {
    cout << i << ":";
    for (auto x: yss[i]) {
      cout << x << " ";
    }
    cout << endl;
  }
  */

  int res = 0;
  for (int i = 0; i <= M/2; i++) {
    int j = (M-i)%M;
    auto& ys_i = yss[i];
    auto& ys_j = yss[j];

    if (i != j) {
      while (!ys_i.empty() && !ys_j.empty()) {
        ys_i.pop_back();
        ys_j.pop_back();
        res++;
      }
    } else {
      while (ys_i.size() >= 2) {
        ys_i.pop_back();
        ys_j.pop_back();
        res++;
      }
    }
  }

  /*
  cout << endl;
  for (int i = 0; i < M; i++) {
    cout << i << ":";
    for (auto x: yss[i]) {
      cout << x << " ";
    }
    cout << endl;
  }
  */


  for (int i = 0; i < M; i++) {
    const auto& ys_i = yss[i];
    for (int j = 0; j < ((int)ys_i.size())-1; j++) {
      //cout << j << " " << ys_i.size() << endl;
      if (ys_i[j] == ys_i[j+1]) {
        res++;
        j++;
      }
    }
  }

  cout << res << endl;


  return 0;
}
