#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define SREP(s,i,m) for(unsigned int i = s; i < m; ++i)
#define REP(i,m) SREP(0,i,m)
using namespace std;

#ifdef _MSC_VER
using LONG = __int64;
using ULONG = unsigned __int64;
#else
using LONG = long long int;
using ULONG = unsigned long long int;
#endif

const int MAX_X = 101'000;
// 二乗を計算する。
int sq(int x) { return x * x; }
int main(void) {
  int N, M;
  cin >> N >> M;
  vector<int> X(N);
  REP(i, N) {
    cin >> X[i];
  }
  vector<int> box(M);
  vector<int> box2(MAX_X);
  vector<int> used(M);
  REP(i, N) {
    box[X[i] % M]++;
    box2[X[i]]++;
  }
  used[0] = box[0];
  SREP(1, i, (M + 1) / 2) {
    used[M - i] = used[i] = min(box[i], box[M - i]);
  }
  if (M % 2 == 0) {
    int idx = M / 2;
    used[idx] = box[idx];
  }
  int count = 0;
  count += used[0] / 2;
  SREP(1, i, (M + 1) / 2) {
    count += used[i];
  }
  if (M % 2 == 0) {
    int idx = M / 2;
    count += used[idx] / 2;
  }
  vector<int> rest(M);
  REP(i, M) {
    rest[i] = box[i] - used[i];
  }
  vector<int> pair_count(M);
  REP(i, MAX_X) {
    int m = i % M;
    pair_count[m] += box2[i] / 2;
  }
  REP(i, M) {
    count += min(pair_count[i], rest[i] / 2);
  }
  cout << count << endl;
  return 0;
}
