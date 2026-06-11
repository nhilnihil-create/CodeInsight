#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  int x=0;
  int n;
  int m=0;
  cin >> n;
  string s;
  cin >> s;
  
  for(int i=0; i<n; i++){
    if(s[i] == 'I'){
      x++;
    }
    if(s[i] == 'D'){
      x--;
    }
    if(x >= m){
      m = x;
    }
  }
  
  cout << m << endl;
  
	return 0;
}
