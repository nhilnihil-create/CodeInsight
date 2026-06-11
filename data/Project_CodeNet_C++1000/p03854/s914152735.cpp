#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  bool ok = true;
  int k = S.size() - 1;
  while (k > 0) {
    if (S.at(k) == 'm') {
      if (k > 3) {
        if (S.at(k - 1) == 'a' && S.at(k - 2) == 'e' && S.at(k - 3) == 'r' && S.at(k - 4) == 'd') {
          k -= 5;
        }
        else {
          ok = false;
          break;
        }
      }
      else {
        ok = false;
        break;
      }
    }
    else if (S.at(k) == 'e') {
      if (k > 3) {
        if (S.at(k - 1) == 's' && S.at(k - 2) == 'a' && S.at(k - 3) == 'r' && S.at(k - 4) == 'e') {
          k -= 5;
        }
        else {
          ok = false;
          break;
        }
      }
      else {
        ok = false;
        break;
      }
    }
    else if (k > 1) {
      if (S.at(k - 2) == 'm') {
        if (k > 5) {
          if (S.at(k - 1) == 'e' && S.at(k - 3) == 'a' && S.at(k) == 'r' && S.at(k - 4) == 'e' && S.at(k - 5) == 'r' && S.at(k - 6) == 'd') {
            k -= 7;
          }
          else {
            ok = false;
            break;
          }
        }
        else {
          ok = false;
          break;
        }
      }
      else if (S.at(k - 2) == 's') {
        if (k > 4) {
          if (S.at(k - 1) == 'e' && S.at(k - 3) == 'a' && S.at(k) == 'r' && S.at(k - 4) == 'r' && S.at(k - 5) == 'e') {
            k -= 6;
          }
          else {
            ok = false;
            break;
          }
        }
        else {
          ok = false;
          break;
        }
      }
      else {
        ok = false;
        break;
      }
    }
    else {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}
 