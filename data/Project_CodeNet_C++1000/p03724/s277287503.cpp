#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
#include<numeric>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> tot(n+1, 0);

  rep (i, m) {
    int tmpa, tmpb;
    cin >> tmpa >> tmpb;
    tot[tmpa]++; tot[tmpb]++;
  }
  rep (i, n+1) {
    if (tot[i] % 2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
