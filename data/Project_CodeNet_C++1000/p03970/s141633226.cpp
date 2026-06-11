#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  string S;
  cin >> S;
  int ans = 0;
  if (S[0]!='C') ans++;
  if (S[1]!='O') ans++;
  if (S[2]!='D') ans++;
  if (S[3]!='E') ans++;
  if (S[4]!='F') ans++;
  if (S[5]!='E') ans++;
  if (S[6]!='S') ans++;
  if (S[7]!='T') ans++;
  if (S[8]!='I') ans++;
  if (S[9]!='V') ans++;
  if (S[10]!='A') ans++;
  if (S[11]!='L') ans++;
  if (S[12]!='2') ans++;
  if (S[13]!='0') ans++;
  if (S[14]!='1') ans++;
  if (S[15]!='6') ans++;
  cout << ans << endl;
}