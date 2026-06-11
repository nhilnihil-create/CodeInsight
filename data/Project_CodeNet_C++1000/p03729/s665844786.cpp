#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  string a , b , c;
  cin >> a >> b >> c;
  int k = a.size() - 1;
  int l = b.size() - 1;
  if(a[k] == b[0] && b[l] == c[0])cout << "YES" << endl;
  else cout << "NO" << endl;
}
