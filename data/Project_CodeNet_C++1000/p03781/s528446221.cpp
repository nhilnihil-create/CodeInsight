#include <bits/stdc++.h>
using namespace std;
int main(){
  int X;
  cin >> X;
  int p = 0;
  int i = 0;
  while (1){
    p+=i;
    if (X <= p){
      cout << i;
      break;
    }
    i++;
  }
}