#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if(a == 1 && b != 1){
  cout << "Alice" << endl;}
  else if(a != 1 && b == 1){
  cout << "Bob" << endl;} 
  else if(a < b && a != 1){
  cout << "Bob" << endl;}
  else if(a > b && b != 1){
  cout << "Alice" << endl;}
  else{
  cout << "Draw" << endl;}
}