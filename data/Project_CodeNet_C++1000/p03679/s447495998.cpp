#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  int x , a , b;
  cin >> x >> a >> b;
  if(b <= a)cout << "delicious" << endl;
  else if(b - a <= x)cout << "safe" << endl;
  else cout << "dangerous" << endl;
}
