#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int x = 0;
  int a[n];

  for(int i = 0; i < n; i++) {
    if(s[i] == 'I') x++;
    else if(s[i] == 'D') x--;
    a[i] = x;
  }
  cout << max(0,*max_element(a,a+n)) << endl;
  return 0;
}