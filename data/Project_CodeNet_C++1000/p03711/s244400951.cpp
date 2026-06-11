//組の練習？

#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int x, y;
  cin >> x >> y;

  vector <int> vec = {0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2};
  if (vec.at(x) == vec.at(y)) cout << "Yes" << endl;
  else cout << "No" << endl;
}
