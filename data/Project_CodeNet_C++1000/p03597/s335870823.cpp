#include <bits/stdc++.h>
using namespace std;

int main(){
  int mass;
  int white;
  int black;
  
  cin >> mass >> white;
  
  black = (mass * mass) - white;
  
  cout << black << endl;
}