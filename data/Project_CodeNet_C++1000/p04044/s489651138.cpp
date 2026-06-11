#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  string ans;
  for(string s: a) {
    ans += s;
  }
  cout << ans;
}