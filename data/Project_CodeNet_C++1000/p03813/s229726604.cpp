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
  int N;
  cin >> N;
  if(N < 1200){
    cout << "ABC" << endl;
  }
  else{
    cout << "ARC" << endl;
  }
}