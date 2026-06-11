#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
#define PN() {cout << "No" << endl; return 0;}
#define PY() {cout << "Yes" << endl; return 0;}

int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a.begin(), a.end());
  int am = a[n-1];
  bool is_alleq = true;
  for(int i=0;i<n;i++){
    if(a[i] <= am-2) PN()
  	if(a[i]!=am) is_alleq = false;
  }
  if(is_alleq && am <= n / 2) PY()
  else if(is_alleq && am+1 == n) PY()
  else if(is_alleq) PN();
  int pos = 0;
  while(a[pos]==am-1) pos++;
  if(pos <= am-1 && 2 * (am-pos) <= n-pos) PY()
  else PN()
  return 0;
}