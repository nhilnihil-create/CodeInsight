#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>
#include <queue>
#include <stack>

using namespace std;

#define mod (1e9 + 7)
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()

typedef long long ll;



void solve1()
{
  ll a, b, x; cin >> a >> b >> x;
  ll ans = b/x - (a-1)/x;
  if(a == 0 && x != 1) {
      ans ++;
  }
  cout << ans << endl;
}

int main()
{
    solve1();
}