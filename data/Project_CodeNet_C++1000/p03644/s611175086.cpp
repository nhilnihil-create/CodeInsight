#include<bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  if(n == 1) {
    cout << 1 << endl;
  }
  else {
    int doubles = 2;
    while(doubles <= n) {
      doubles *=2;
    }
    doubles /= 2;
    cout << doubles << endl;
  }
}