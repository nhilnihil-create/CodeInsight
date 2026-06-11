#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  string s; cin >> s;
  cout << s[0] << s.size() - 2 << s[s.size() - 1] << endl;
  return;
}

int main(){
  solve();
  return 0;
}
