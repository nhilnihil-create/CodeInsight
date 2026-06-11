#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,y;
  cin >> x >> y;
  
  int group[] = {1,3,1,2,1,2,1,1,2,1,2,1};
  
  if ( group[x-1] == group[y-1] ) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  cout << endl;

  
}
