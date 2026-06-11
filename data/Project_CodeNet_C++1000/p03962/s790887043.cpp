#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, s;
  cin >> a >> b >> c;
  if(a == b && b==c){
  s = 1;}
  else if(a != b && b != c && c!= a){
  s = 3;}
  else{
  s = 2;}
  cout << s << endl;
}