// darksta5's template v2.0

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int par1[200050], par2[200050];

int find1(int i) {
  int x = i;
  while (x != par1[x]) {
    x = par1[x];
  }

  return par1[i] = x;
}

int find2(int i) {
  int x = i;
  while (x != par2[x]) {
    x = par2[x];
  }

  return par2[i] = x;
}

void uni1(int i, int j) {
  int x = find1(i), y = find1(j);
  if (x != y) {
    par1[y] = x;
  }
}

void uni2(int i, int j) {
  int x = find2(i), y = find2(j);
  if (x != y) {
    par2[y] = x;
  }
}

ll make_key(int x, int y) {
  return (ll)x*200050LL+(ll)y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, r1, r2;
  cin >> n >> r1 >> r2;
  for (int i = 0; i < n; i++) {
    par1[i] = i;
    par2[i] = i;
  }

  for (int i = 0; i < r1; i++) {
    int x, y;
    cin >> x >> y;
    uni1(x-1, y-1);
  }

  for (int i = 0; i < r2; i++) {
    int x, y;
    cin >> x >> y;
    uni2(x-1, y-1);
  }

  unordered_map<ll, int> cnt;
  for (int i = 0; i < n; i++) {
    ll key = make_key(find1(i), find2(i));
    cnt[key]++;
  }

  for (int i = 0; i < n; i++) {
    ll key = make_key(find1(i), find2(i));
    if (i < n-1) {
      cout << cnt[key] << " ";
    } else {
      cout << cnt[key] << endl;
    }
  }
}