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
const int MOD = 1000000007;

int main() {
  string s; cin >> s;
  string result = ((s.length()%2==1) ^ (s[0]==s[s.length()-1])) ? "First" : "Second";
  cout << result << endl;
  return 0;
}