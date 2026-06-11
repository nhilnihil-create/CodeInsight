#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int H,W;
  cin >> H >> W;
  char Matrix[H][W];
  int alpha[26];
  for (int i = 0; i < 26; i++) alpha[i] = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> Matrix[i][j];
      alpha[Matrix[i][j] - 'a']++;
    }
  } 
  int even = 0;
  int odd = 0;
  if (H == 1 || W == 1) {
    for (int i = 0; i < 26; i++) {
      if (alpha[i] % 2 == 0) {
        even++;
      } else {
        odd++;
      }
    }
    int other = H;
    if (H == 1) {
      other = W;
    }
    if (other % 2 == 1) {
      if (odd == 1) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    } else {
      if (odd == 0) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  } else {
    if (H % 2 == 0 && W % 2 == 0) {
      int f = 0;
      for (int i = 0; i < 26; i++) {
        if (alpha[i] % 4 != 0) {
          f++;
        }
      }
      if (f == 0) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    } else if (H % 2 == 1 && W % 2 == 1) {
      int a = 0;
      int b = 0;
      for (int i = 0; i < 26; i++) {
        if (alpha[i] % 4 == 2) {
          a++;
        }
        if (alpha[i] % 2 == 1) {
          b++;
        }
      }
      if (a <= ((H-1)/2) + ((W-1)/2) && b == 1) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    } else {
      int other = H;
      if (H % 2 == 1) {
        other = W;
      }
      int c = 0;
      int d = 0;
      for (int i = 0; i < 26; i++) {
        if (alpha[i] % 4 == 2) {
          c++;
        }
        if (alpha[i] % 2 == 1) {
          d++;
        }
      }
    if (d == 0 && c <= other/2) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
  return 0;
}