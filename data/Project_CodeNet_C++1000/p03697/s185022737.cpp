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
  if(A + B >= 10){
    cout << "error" << endl;
  }
  else{
    cout << A + B << endl;
  }
}
