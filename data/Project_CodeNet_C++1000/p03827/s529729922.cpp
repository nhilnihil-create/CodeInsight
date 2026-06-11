#include <bits/stdc++.h>
using namespace std;

int main() {
  int count = 0, n;
  string s;
  cin >> n >> s;
  int max_count = 0;

  for(char c : s) {
    if(c == 'I') {
      count++;
      if(count >= max_count) {
        max_count = count;
      }
    }
    else if(c == 'D'){
      count--;
    }
  }
  cout << max_count << endl;
}