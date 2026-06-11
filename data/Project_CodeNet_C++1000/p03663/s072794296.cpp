#define DEBUG(x) cout << #x << " = " << x << endl
#include<bits/stdc++.h>
using namespace std;
void ask(long long num) {
  cout << "? " << num << endl;
}
char receive() {
  char x; cin >> x;
  return x;
}
int main() {
  int l = 0;
  while (l <= 10) { 
    ask(pow(10, l));
    if (receive() == 'N') {
      break;
    }
    l++;
  }
  if (l == 11) {
    l = 1;
    while (l <= 10) {
      ask(pow(10, l) - 1);
      if (receive() == 'Y'){
        break;
      }
      l++;
    }
  }

  long long sf = 0;
  for (int i = 1; i <= l - 1; i++) {
    int left = i == 1 ? 0 : -1;
    int right = 10;
    while (left + 1 < right) {
      int mid = (left + right) / 2;
      long long num = sf * 10 + mid;
      cout << "?" << " " << num << endl;
      char a; cin >> a;
      if (a == 'Y') {
        left = mid;
      } else {
        right = mid;
      }
    }
    // the i-th digit is left
    sf = sf * 10 + left;
  }
  int last = -1;
  int start = l == 1 ? 1 : 0;
  for (int d = start; d <= 9; d++) {
    cout << "? " << sf * 100 + d * 10 << endl;
    char a; cin >> a;
    if (a == 'Y') {
      last = d;
      break;
    }
  }

  cout << "! " << sf * 10 + last << endl;
}
