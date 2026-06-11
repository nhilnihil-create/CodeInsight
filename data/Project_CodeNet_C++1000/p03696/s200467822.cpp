#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int need_left = 0, pointer = 0;
  for (int i=0; i<N; i++) {
    if (S[i]=='(') pointer++;
    else if (pointer==0) need_left++;
    else pointer--;
  }
  int need_right = pointer;
  string res = "";
  for (int i=0; i<need_left; i++) res += '(';
  res += S;
  for (int i=0; i<need_right; i++) res += ')';
  cout << res << endl;
  return 0;
}