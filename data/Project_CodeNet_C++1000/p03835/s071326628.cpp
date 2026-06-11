#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int k,s,cnt = 0;
  cin >> k >> s;
  
  for(int i = 0; i <= k; i++) {
    for(int j = 0; j <= k; j++) {
      if(0 <= (s-i-j) & (s-i-j) <= k)
        cnt++;
    }
  }

  cout << cnt << endl;
}
