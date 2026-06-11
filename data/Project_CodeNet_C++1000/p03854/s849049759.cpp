#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(void) {
  string s;
  cin >> s;
  int i = 0, tmp;
  bool key = false;

  while(1) {
    tmp = i;
    if(0 == s.compare(i,11,"dreameraser")) {
      i += 11;
    } else if (0 == s.compare(i,10,"dreamerase")) {
      i += 10;
    } else if (0 == s.compare(i,7,"dreamer")) {
      i += 7;
   } else if(0 == s.compare(i,5,"dream")) {
      i += 5;
    } else if (0 == s.compare(i,6,"eraser")) {
      i += 6;
    }else if (0 == s.compare(i,5,"erase")) {
      i += 5;
    }
   
    //cout << i << endl;
    if (tmp == i) {
      key = false; break;
    } else if (i == s.size()) {
      key = true; break;
    } 
  }

  if(key) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}