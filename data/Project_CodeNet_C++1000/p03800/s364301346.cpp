#include <bits/stdc++.h>
using namespace std;

int n;
string s;
bool ok(vector<bool> &is_sheep, bool s1, bool s2) {
  is_sheep[0] = s1;
  is_sheep[1] = s2;
  for (int i=1; i<n-1; i++) {
    if (is_sheep[i]) {
      if (s[i] == 'o') {
        is_sheep[i+1] = is_sheep[i-1];
      } else {
        is_sheep[i+1] = !is_sheep[i-1];
      }
    } else {
      if (s[i] == 'o') {
        is_sheep[i+1] = !is_sheep[i-1];
      } else {
        is_sheep[i+1] = is_sheep[i-1];
      }
    }
  }
  if (is_sheep[n-1]) {
    if (s[n-1] == 'o' ^ is_sheep[0] == is_sheep[n-2]) {
      return false;
    }
  } else {
    if (s[n-1] == 'x' ^ is_sheep[0] == is_sheep[n-2]) {
      return false;
    }
  }
  if (is_sheep[0]) {
    return s[0] == 'o' ^ is_sheep[n-1] != is_sheep[1];
  } else {
    return s[0] == 'x' ^ is_sheep[n-1] != is_sheep[1];
  }
}
int main() {
  cin>>n;
  cin>>s;
  vector<bool> is_sheep(n);
  bool state[2] = {true, false};
  for (bool s1: state) {
    for (bool s2: state) {
      if (ok(is_sheep, s1, s2)) {
        for (bool b: is_sheep) {
          if (b) {
            cout<<"S";
          } else {
            cout<<"W";
          }
        }
        cout<<endl;
        return 0;
      }
    }
  }
  cout<<-1<<endl;
}