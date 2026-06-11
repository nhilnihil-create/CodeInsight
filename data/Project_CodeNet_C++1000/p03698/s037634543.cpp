#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  string s;
  cin >> s;
  int n=s.size();
  vector<char> a(n);
  for(int i=0; i<n; i++){
    a[i] = s[i];
  }
  sort(a.begin(),a.end());
  string ans="yes";
  for(int i=0; i<n-1; i++){
    if(a[i] == a[i+1]){
      ans = "no";
    }
  }
  
  cout << ans << endl;
	return 0;
}
