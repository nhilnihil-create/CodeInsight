#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b,cu,out;
  cin >> n;
  cu = 0;
  out = 0;
  vector<int> vec(0);
  for (int i = 0 ; i < n ; i++ ) {
    cin >> a;
    vec.push_back(a);
  }
  b = 1;
  for (int i = 0;i < n ; i++){
    cu++;
    if (cu == n){
      out = 1;
      break;
    }
    if (vec.at(b-1) == 2){
      break;
    }
    b = vec.at(b-1);
  }
  if (out == 1){
    cout << -1;
  }
  else {
    cout << cu;
  }
}  