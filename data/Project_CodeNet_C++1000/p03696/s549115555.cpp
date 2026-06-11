#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  
  int left = 0, right = 0;
  for(int i = 0; i < n; i++){
    if(s.at(i) == '(') left++;
    else if(left > 0) left--;
    else right++;
  }
  
  for(int i = 0; i < right; i++) cout << '(';
  cout << s;
  for(int i = 0; i < left; i++) cout << ')';
  cout << endl;
}