#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  char a , b;
  cin >> a >> b;
  if(a == 'H')cout << b << endl;
  else{
    if(b == 'H')cout << 'D' << endl;
    else cout << 'H' << endl;
  }
}
