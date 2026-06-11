#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <climits>
#include <iomanip>
#include <bitset>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>

using namespace std;

const int N = 100005;

int n, m;
int arr[N];
long long ans[N];
int pref[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  for (int i = 1; i < n; i++) {
    int s = arr[i - 1], t = arr[i];
    if (s < t) {
      ans[1] += (t - s);
      ans[s + 1] -= (t - s); //a
      pref[s + 2]++;
      pref[t + 1]--;
      ans[t + 1]--;
      ans[s + 1] += (t - (s + 1) + 1); //b
      ans[t + 1] += (t - s); //c
    } else if (t < s) {
      ans[1] += t;
      ans[t + 1]--;
      pref[2]++;
      pref[t + 1]--; //a
      ans[t + 1] += (m - s + t);
      ans[s + 1] -= (m - s + t); //b
      pref[s + 2]++;
      ans[s + 1] += (m - (s + 1) + 1 + t); //c
    }
  }
  for (int i = 1; i < N; i++) {
    pref[i] += pref[i - 1];
  }
  long long res = 2e18;
  for (int i = 1; i <= m; i++) {
    ans[i] = ans[i - 1] + ans[i] - pref[i];
    res = min(res, ans[i]);
  }
  cout << res << endl;
  return 0;
}
