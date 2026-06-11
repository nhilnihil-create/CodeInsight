#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <queue>
#include <iomanip>

#define rep(i,n) for(int i=0; i<(int)(n); i++)
using namespace std;

int N;
vector<long> A(100005);
vector<long> ans(100005);
vector<pair<long, int>> P(1000005);

int main() {
  cin >> N;
  rep(i, N) {
    cin >> A.at(i);
    P.at(i) = make_pair(A.at(i), i);
  }
  sort(P.rbegin(), P.rend());
  pair<long, int> pfirst = P.at(0);
  int num = 1;
  long dd = pfirst.first;
  int pos = pfirst.second;
  for (int i=1; i<N; i++) {
    pair<long, int> psecond = P.at(i);
    if (psecond.first < dd) {
      ans.at(pos) += (dd - psecond.first)*num;
      dd = psecond.first;
    }
    if (psecond.second < pos) {
      pos = psecond.second;
    }
    num++;
  }
  ans.at(0) += dd*num;
  rep(i, N) {
    cout << ans.at(i) << endl;
  }
}

// (1, 1), (5, 2), (4, 3)
// (5, 2), (4, 3), (1, 1)
