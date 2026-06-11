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
  int n = s.size();
  for(int i = 0; i < n; i++){
    if(s[i] == '9'){
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
  return;
}

int main(){
  solve();
  return 0;
}
