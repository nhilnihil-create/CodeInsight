#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
set<int> a;
rep(i,3){
  int x;
  cin >> x;
  a.insert(x);
}
cout << a.size() << endl;
 }