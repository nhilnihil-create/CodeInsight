#include <bits/stdc++.h>
using namespace std;

int main() {
  string odd, even, ans;
  cin >> odd >> even;
  for(int i = 0; i < odd.size(); i++) {
    ans += odd[i];
    ans += even[i];
  }
  if(odd.size() > even.size()) ans.pop_back();
  cout << ans << endl;
}