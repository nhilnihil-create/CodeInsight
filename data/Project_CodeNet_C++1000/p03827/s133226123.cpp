#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x = 0, result = 0;
  string s;
  cin >> n >> s;


  for (int i = 0; i < n; i++){
    if(s[i] == 'I'){
      x += 1;
      if(x > result){
        result = x;
      }
    }else if (s[i] == 'D'){
      x -= 1;
    }
  }
  
  cout << result << endl;
}