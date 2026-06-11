#include <bits/stdc++.h>
using namespace std;
int main() {
  int W,a,b;
  cin >> W >> a >> b;
  if (a == b){
    cout << 0 << endl;
    return 0;
  }
  else if (a < b){
    cout << max(b-a-W,0) << endl;
    return 0;
  }
  else if (b < a){
    cout << max(a-b-W,0) << endl;
  }
}