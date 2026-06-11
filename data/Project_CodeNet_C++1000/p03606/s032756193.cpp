#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  int t = 0;
  cin >> n;
  for (int i=0; i<n; i++){
    int l,r;
    cin >> l >> r;
    t += (r-l+1);
    if (t > 100000){
      t = 100000;
      break;
    }
  }
  cout << t << endl;
}
