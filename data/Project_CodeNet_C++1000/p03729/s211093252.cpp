#include <bits/stdc++.h>
using namespace std;
 
int main (){
  
  string x, y, z;
  cin >> x >> y >> z;
  if (x[x.size()-1] == y[0] && y[y.size()-1] == z[0]) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}