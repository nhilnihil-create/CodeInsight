#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
  string a , b , c;
  cin >> a >> b >> c;
  int k = 0;
  int l = 0;
  int m = 0;
  for(int i = 0;i < 25; i++){
    if(a[0] == alphabet[i])break;
    k++;
  }
  for(int i = 0;i < 25; i++){
    if(b[0] == alphabet[i])break;
    l++;
  }
  for(int i = 0;i < 25; i++){
    if(c[0] == alphabet[i])break;
    m++;
  }
  cout << ALPHABET[k] << ALPHABET[l] << ALPHABET[m] << endl;
}

