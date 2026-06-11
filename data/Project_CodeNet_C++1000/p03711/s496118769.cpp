#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,y;cin>>x>>y;
  int a[] = {1, 3, 5, 7, 8, 10, 12};
  int b[] = {4, 6, 9, 11};
  
  if (x == y) {
    cout << "Yes" << endl;
    return 0;
  }
  
  int x_ = 0;
  int y_ = 0;
  for (int i=0; i<7;i++){
    if (a[i] == x) x_ = 1;
    if (a[i] == y) y_ = 1;
  }
  for (int i=0; i<4;i++){
    if (b[i] == x) x_ = 2;
    if (b[i] == y) y_ = 2;
  }

  if (x_ == y_) {
    cout << "Yes" << endl;
    return 0;
  }
  
  cout << "No" << endl;

}