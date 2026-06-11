#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};

// stringの要素を検索
bool string_exist(string s, char c) {
  auto itr = find(s.begin(), s.end(), c);
  size_t index = distance(s.begin(), itr);
  if (index!=s.size()) {
    return true;
  }
  else {
    return false;
  }
}

int main() {
  int N, K;
  cin >> N >> K;
  vector<char> D(K);
  for (int i=0; i<K; i++) cin >> D[i];
  int num = N;
  while (true) {
    string s = to_string(num);
    bool exist = false;
    for (int i=0; i<K; i++) {
      if (string_exist(s, D[i])) {
        exist = true;
        break;
      }
    }
    if (exist) num++;
    else {
      cout << s << endl;
      break;
    }
  }
  return 0;
}