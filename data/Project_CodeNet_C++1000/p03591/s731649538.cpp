#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

int main() {
  string s, t = "YAKI";
  cin >> s;
  for (int i = 0; i < 4; i++) {
      if(s[i]!=t[i]){
        cout << "No" << endl;
        return 0;
      }
  }
  cout << "Yes" << endl;
  return 0;
}