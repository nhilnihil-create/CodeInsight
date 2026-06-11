#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  int a , b , c;
  cin >> a >> b >> c;
  if(b - a == c - b)cout << "YES" << endl;
  else cout << "NO" << endl;
}
