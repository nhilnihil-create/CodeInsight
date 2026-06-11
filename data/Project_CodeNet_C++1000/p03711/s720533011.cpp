#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int x,y;
  cin >> x >> y;
  int group[13] = {0,1,3,1,2,1,2,1,1,2,1,2,1};
  if (group[x] == group[y]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  } 
  return 0;
}