#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

bool comp(pair<int, long long> a, pair<int, long long> b) {
  return a.first < b.first;
}

void solve(vector<long long>& a, int cur, set<int> comb, vector<long long>& rets, int K) {
  if (comb.size() == K) {
    vector<pair<int, long long> > p;
    for (set<int>::iterator i = comb.begin(); i != comb.end(); ++i) {
      p.push_back(make_pair(*i, a[*i]));
    }

    sort(p.begin(), p.end(), comp);

    // find the larger building than the first one
    int cursor = 0;
    long long largest = 0;
    long long ret = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (i == p[cursor].first) {
        if (p[cursor].second <= largest) {
          ret += largest + 1 - p[cursor].second;
          largest = largest + 1;
        } else {
          largest = p[cursor].second;
        }
        ++cursor;
        if (cursor == p.size())
          break;
      } else {
        largest = max(a[i], largest);
      }
    }

    rets.push_back(ret);

  } else {
    for (int i = cur + 1; i < a.size(); ++i) {
      set<int> tmp = comb;
      tmp.insert(i);
      solve(a, i, tmp, rets, K);
    }
  }
}

int main(int argc, char* argv[]) {
  int N, K;
  cin >> N >> K;

  vector<long long> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  set<int> comb;
  vector<long long> rets;
  solve(a, -1, comb, rets, K);

  long long ret = 1000000000000000LL;
  for (int i = 0; i < rets.size(); ++i)
    ret = min(rets[i], ret);

  cout << ret << endl;

  return 0;
}