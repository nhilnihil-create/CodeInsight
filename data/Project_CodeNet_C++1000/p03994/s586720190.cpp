#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  string S;
  int K;
  cin >> S >> K;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == 'a') continue;
    if ('z' - S[i] + 1 <= K) {
      K -= 'z' - S[i] + 1;
      S[i] = 'a';
    }
  }
  if (K != 0)
    S[S.size() - 1] = (char)(((S[S.size() - 1] - 'a') + K) % 26 + 'a');
  cout << S << endl;
  return 0;
}