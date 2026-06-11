#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  int a , b;
  cin >> a >> b;
  int k = a + b;
  if(k < 10)cout << k << endl;
  else cout << "error" << endl;
}
