#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int g(int x){
  if(x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12)return 0;
  else if(x == 4 || x == 6 || x == 9 || x == 11)return 2;
  else return 3;
}

int main(){
  int a , b;
  cin >> a >> b;
  if(g(a) == g(b))cout << "Yes" << endl;
  else cout << "No" << endl;
}

