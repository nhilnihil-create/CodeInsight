#include <bits/stdc++.h>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <numeric>
using namespace std;

int abs(int num){
   if (num > 0)
      return num;
   else
      return -num;
}

int main(){
  int A,B;
  cin >> A >> B;
  int C = 0;
  C = A + B;
  if(C%3 == 0 || A%3 == 0 || B%3 == 0){
    cout << "Possible" << endl;
  }
  else{
    cout << "Impossible" << endl;
  }
}