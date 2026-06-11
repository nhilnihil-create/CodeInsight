#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  int x , a , b;
  cin >> x >> a >> b;
  int k = a - x;
  int l = b - x;
  if(k < 0)k = x - a;
  if(l < 0)l = x - b;
  if(k < l)cout << 'A' << endl;
  else cout << 'B' << endl;
}