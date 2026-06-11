#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string str;
  cin >> str;
  
  int x = str.find_first_of('A');
  int y = str.find_last_of('Z');
  
  int ans = y - x + 1;
  
  cout << ans << endl;

}
             
 