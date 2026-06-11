#include <bits/stdc++.h>
using namespace std;

int main(){
  int X; cin >> X;
  int add=1;
  int max=0;
  while(1){
    max+=add;
    if(X<=max) break;
    add++;
  }
  cout << add << endl;
}