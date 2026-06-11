#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int main() {
  string S, T; cin >> S >> T;
  vector<LL> sumS(S.size() + 1), sumT(T.size() + 1);
  sumS[0] = 0, sumT[0] = 0;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == 'A') sumS[i + 1] = sumS[i] + 1;
    else             sumS[i + 1] = sumS[i] + 2;
  }
  for (int i = 0; i < T.size(); ++i) {
    if (T[i] == 'A') sumT[i + 1] = sumT[i] + 1;
    else             sumT[i + 1] = sumT[i] + 2;
  }

  int q; cin >> q;
  for (int i = 0; i < q; ++i) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    if (((sumS[b] - sumS[a-1]) % 3) == ((sumT[d] - sumT[c-1]))%3) cout << "YES" << endl;
    else                                                          cout << "NO" << endl;
  }
}
