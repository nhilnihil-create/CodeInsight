#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, s, n) for (int i = (s); i < (n); ++i)
#define rrep(i, n, g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define len(x) (int)(x).size()
#define dup(x, y) (((x) + (y)-1) / (y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int x, y;
  cin >> x >> y;
  set<int> s1 = {1, 3, 5, 7, 8, 10, 12};
  set<int> s2 = {4, 6, 9, 11};
  set<int> s3 = {2};
  if ((s1.count(x) == 1) && (s1.count(y) == 1))
    cout << "Yes";
  else if ((s2.count(x)) == 1 && (s2.count(y) == 1))
    cout << "Yes";
  else if ((s3.count(x)) == 1 && (s3.count(y) == 1))
    cout << "Yes";
  else
    cout << "No";
}