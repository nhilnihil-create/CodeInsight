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

const int N = 300005;

int n;
int arr[N];
map <int, long long> frn;
map <int, long long> bck;

void rig(int n) {
  multiset <long long> ms;
  long long sum = 0;
  for (int i = 0; i < 3 * n; i++) {
    if (ms.size() < n) {
      ms.insert(arr[i]);
      sum += arr[i];
    } else {
      if (arr[i] > *ms.begin()) {
        sum -= *ms.begin();
        sum += arr[i];
        ms.erase(ms.begin());
        ms.insert(arr[i]);
      }
    }
    if (ms.size() < n) {
      frn[i] = -1;
    } else {
      frn[i] = sum;
    }
  }
}

void lef(int n) {
  multiset <long long> ms;
  long long sum = 0;
  for (int i = 3 * n - 1; i >= 0; i--) {
    if (ms.size() < n) {
      ms.insert(arr[i]);
      sum += arr[i];
    } else {
      if (arr[i] < *(--ms.end())) {
        sum -= *(--ms.end());
        sum += arr[i];
        ms.erase(--ms.end());
        ms.insert(arr[i]);
      }
    }
    if (ms.size() < n) {
      bck[i] = -1;
    } else {
      bck[i] = sum;
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < 3 * n; i++) {
    scanf("%d", &arr[i]);
  }
  rig(n);
  lef(n);
  long long ans = -2e18;
  for (int i = 1; i < 3 * n - 1; i++) {
    if (frn[i - 1] != -1 && bck[i + 1] != -1) {
      ans = max(ans, frn[i - 1] - bck[i + 1]);
    }
    if (frn[i] != -1 && bck[i + 1] != -1) {
      ans = max(ans, frn[i] - bck[i + 1]);
    }
    if (frn[i - 1] != -1 && bck[i] != -1) {
      ans = max(ans, frn[i - 1] - bck[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
