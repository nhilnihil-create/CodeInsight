#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  string s,s1;
  cin >> s;
  s1 = s;
  int n = s.size();
  
  int ans = 0;
  
  int i = 0,j = n-1;
  while(1){
    if(s[i] == 'A'){
      break;
    }
    i++;
  }
  while(1){
    if(s[j] == 'Z'){
      break;
    }
    j--;
  }  

  ans = j-i+1;
  
  cout << ans << endl;
  
  
}