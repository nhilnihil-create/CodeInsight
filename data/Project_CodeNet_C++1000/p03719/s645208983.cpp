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
  int A,B,C;
  cin >> A >> B >> C;
  if(C >= A && C <= B){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
