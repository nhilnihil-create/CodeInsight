#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
typedef long long ll;
using namespace std;
void solve(){
  int n, cnt = 0; cin >> n;
  string s; cin >> s;
  vector<char> v(n);
  for(int i = 0; i < n; i++){
    v[i] = s[i];
  }
  for(int i = 0; i < n; i++){
    if(s[i] == '(') cnt++;
    else{
      if(cnt > 0) cnt--;
      else v.insert(v.begin(), '(');
    }
  }
  for(int i = 0; i < cnt; i++){
    v.push_back(')');
  }
  for(int i = 0; i < v.size(); i++){
    cout << v[i];
  }
  cout << endl;
  return;
}

int main(){
  solve();
  return 0;
}
