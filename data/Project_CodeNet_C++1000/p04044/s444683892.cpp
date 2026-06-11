#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
  int n, l;
  cin >> n >> l;
  string s[n];
  for (int i = 0; i < n; i++)
    cin >> s[i];
  
  for (int i = 0; i < n; i++) {
    for (int j = n-1; j > i; j--) {
      if (s[j] < s[j-1]) {
        string tmp;
        tmp = s[j]; s[j] = s[j-1]; s[j-1] = tmp;
      } 
    }
  }
  for (int i = 0; i < n; i++) {
    cout << s[i];
  }
  cout << endl;
}