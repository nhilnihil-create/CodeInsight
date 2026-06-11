#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  long long n = s.length();

  map<char, int> m;
  for (int i=0; i<n; i++) {
    ++m[s[i]];
  }

  long long ans = n * (n - 1) / 2;
  for (auto e: m) {
    long long v = e.second;
    ans -= v * (v - 1) / 2;
  }
  cout<<ans+1<<endl;
}