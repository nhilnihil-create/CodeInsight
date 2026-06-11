#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  string s;
  cin>>s;
  for (int i=0; i<8; i++) {
    bool i0 = (i >> 2) & 1;
    bool i1 = (i >> 1) & 1;
    bool i2 = i & 1;

    if (i1) {
      if (s[1] == 'o') {
        if (i0 != i2) {
          continue;
        }
      } else {
        if (i0 == i2) {
          continue;
        }
      }
    } else {
      if (s[1] == 'o') {
        if (i0 == i2) {
          continue;
        }
      } else {
        if (i0 != i2) {
          continue;
        }
      }
    }
    vector<bool> is_sheep(n);
    is_sheep[0] = i0;
    is_sheep[1] = i1;
    is_sheep[2] = i2;

    for (int j=3; j<n; j++) {
      if (is_sheep[j-1]) {
        if (s[j-1] == 'o') {
          is_sheep[j] = is_sheep[j-2];
        } else {
          is_sheep[j] = !is_sheep[j-2];
        }
      } else {
        if (s[j-1] == 'o') {
          is_sheep[j] = !is_sheep[j-2];
        } else {
          is_sheep[j] = is_sheep[j-2];
        }
      }
    }
    if (is_sheep[n-1]) {
      if (s[n-1] == 'o' && is_sheep[n-2] != is_sheep[0]) {
        continue;
      } else if (s[n-1] == 'x' && is_sheep[n-2] == is_sheep[0]) {
        continue;
      }
    } else {
      if (s[n-1] == 'o' && is_sheep[n-2] == is_sheep[0]) {
        continue;
      } else if (s[n-1] == 'x' && is_sheep[n-2] != is_sheep[0]) {
        continue;
      }
    }
    if (is_sheep[0]) {
      if (s[0] == 'o' && is_sheep[n-1] != is_sheep[1]) {
        continue;
      } else if (s[0] == 'x' && is_sheep[n-1] == is_sheep[1]) {
        continue;
      }
    } else {
      if (s[0] == 'o' && is_sheep[n-1] == is_sheep[1]) {
        continue;
      } else if (s[0] == 'x' && is_sheep[n-1] != is_sheep[1]) {
        continue;
      }
    }
    for (int j=0; j<n; j++) {
      if (is_sheep[j]) {
        cout<<"S";
      } else {
        cout<<"W";
      }
    }
    cout<<endl;
    return 0;
  }
  cout<<-1<<endl;
}