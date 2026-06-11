#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int x, y;
  cin >> x >> y;
  int a_cnt = 0;
  int b_cnt = 0;
  vector<int> a = {1, 3, 5, 7, 8, 10, 12};
  vector<int> b = {4, 6, 9, 11};
  rep(i, a.size()-1) {
    if(x == a[i]) a_cnt++;
    if(y == a[i]) a_cnt++;
  }
  rep(i, b.size()-1) {
    if(x == b[i]) b_cnt++;
    if(y == b[i]) b_cnt++;
  }
  
  if(a_cnt == 2 || b_cnt == 2) cout << "Yes" << endl;
  else cout << "No" << endl;
}