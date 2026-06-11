#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> x(M), y(M);
  for (int i=0; i<M; i++) cin >> x[i] >> y[i];
  vector<int> num(N, 1);
  vector<bool> red(N, false);
  red[0] = true;
  for (int i=0; i<M; i++) {
    if (red[x[i]-1]) red[y[i]-1] = true;
    num[x[i]-1]--;
    num[y[i]-1]++;
    if (num[x[i]-1]==0) red[x[i]-1] = false;
  }
  cout << count(red.begin(), red.end(), true) << endl;
}