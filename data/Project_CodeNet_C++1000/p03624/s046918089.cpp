#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string a;
  cin >> a;
  set<char> s;
  for(int i=0; i<a.size(); i++) s.insert(a[i]);
  if(s.size()==26) cout << "None" << endl;
  else {
    string ans;
    sort(a.begin(), a.end());
    for(int i=0; i<a.size()-1; i++) {
      if(a[0]!='a') {
        cout << "a" << endl;
        break;
      }
      else if(a[i]!=a[i+1] && a[i+1]!=a[i]+1) {
        ans = a[i]+1;
        break;
      }
      if(i==a.size()-2) {
        ans = a[i+1]+1;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}