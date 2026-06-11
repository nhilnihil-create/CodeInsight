#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  int N = s.size();
  
  for(int i=0; i<N; i +=2) {
    cout << s.at(i);
  }
  return 0;
}