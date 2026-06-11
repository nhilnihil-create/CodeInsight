#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>

#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int INF = pow(2,29);
const int MOD = 1000000007;

int main() {
  string S; cin >> S;
  string cf = "CODEFESTIVAL2016";

  int result = 0;
  rep(i, 16) if (S[i]!=cf[i]) result++;
  cout << result << endl;
  return 0;
}