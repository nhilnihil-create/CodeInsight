#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  string a, b;
  cin >> a >> b;
  string ans = "Alice";
  if (b=="1"&& a=="1") {ans="Draw";}
  else if (b=="1") {ans="Bob";}
  else if (a!="1") {
    if (b.size()>a.size()) {ans = "Bob";}
    else if (b.size()==a.size()) {
      if (a[a.size()-1]==b[b.size()-1]) {ans="Draw";}
      else if (a[a.size()-1]<b[b.size()-1]) {ans="Bob";}
    }
  }
  cout << ans << endl;
}
