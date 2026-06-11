#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  cin>>a;
  map<char, int> m;
  for (char c: a) {
    ++m[c];
  }
  long long ans = 0;
  int n = a.length();
  for (int i=0; i<n; i++) {
    ans += n - i - m[a[i]];
    --m[a[i]];
  }
  cout<<ans+1<<endl;
}