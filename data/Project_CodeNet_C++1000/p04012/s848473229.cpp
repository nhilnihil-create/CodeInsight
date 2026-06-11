#include <bits/stdc++.h>
using namespace std;


int main() {
  string s; cin >> s;
  int ans[1000] = {0};
  for(int i = 0; i < s.size(); i++){
    ans[s[i]]++;
  }
  bool j = true;
  for(int i = 0; i < 1000; i++){
    if(ans[i]%2!=0)j = false;
  }
  if(j) cout << "Yes" << endl;
  else cout <<"No" << endl;
}
