#include <iostream>
#include <string>
using namespace std;

void solve(){
  string s; cin >> s;
  int ans;
  ans = s.find_last_of('Z') - s.find_first_of('A') + 1;
  cout << ans << endl;
}

int main(){
  solve();
  return 0;
}