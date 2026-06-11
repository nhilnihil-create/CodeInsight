#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string a , b , c ;
  cin >> a >> b >> c ;
  cout << ( a.at(a.size()-1) == b.at(0) 
           && b.at(b.size()-1) == c.at(0) ?
           "YES" :
           "NO")
    << endl;
}
    