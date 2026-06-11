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
  if(a % 3 == 0 || b % 3 == 0 || k % 3 == 0)cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}
