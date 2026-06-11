#include <bits/stdc++.h>
using namespace std;
     
int main() {
  string a;
  cin >> a;
  
  //to_stringはC++14 (GCC 5.4.1)で使うように
  a.replace(1, a.size()-2, to_string(a.size()-2));
  cout << a << endl;
}