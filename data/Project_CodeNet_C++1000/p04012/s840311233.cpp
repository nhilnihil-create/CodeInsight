#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  
  int n = s.size();
  
  vector<int> a(26,0);
  
  REP(i,n){
    REP(j,26){
      if(j + 'a' == s[i]){
        a[j]++;
      }
    }
  }
  
  bool can = true;
  REP(i,26) {
    if(a[i] % 2 != 0){
      can = false;
    }
  }
  
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;



}