#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,s=0,x,y;
  cin >> n;
  
  for (int i=0;i<n;i++) {
    cin >> x >> y;
    s += y-x+1;
  }
  cout << s << endl;
}