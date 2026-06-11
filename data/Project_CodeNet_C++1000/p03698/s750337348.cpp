#include <bits/stdc++.h>
#define rep(i,a,n) for (int i =a; i<n; i++) 
using namespace std;

int main() {
  string S; cin >> S;
  int size = S.size();
  int num[26]; rep (i,0,26) num[i] = 0;
  bool check = false;
  rep(i,0,size) {
    int a = (int)(S[i] - 'a');
    num[a]++;
  }
  rep(i,0,26) {
    if (num[i] >=2) check = true;
  }
  if (check) cout << "no" << endl;
  else cout << "yes" << endl;
  
}