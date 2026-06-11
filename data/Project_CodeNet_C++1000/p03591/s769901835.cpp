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
  string sub = S.substr(0, 4);
  if (sub=="YAKI") cout << "Yes" << endl;
  else cout << "No" << endl;
}