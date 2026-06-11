#include <bits/stdc++.h>
using namespace std;
int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int sum = a, m = sum%b;
  string ans = "YES";
  set<int> s;
  while(m != c){
    if(s.count(m)){ ans = "NO"; break; }
    s.insert(m);
    sum += a;
    m = sum%b;
  }
  cout << ans << endl;
}