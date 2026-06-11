#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
  int A;
  int B;
  string isPossible = "Possible";
  cin >> A >> B;
  if(A%3 != 0){
    if(B%3 != 0){
      if((A+B)%3 != 0){
        isPossible = "Impossible";
      }
    }
  }
  cout << isPossible << endl;
}