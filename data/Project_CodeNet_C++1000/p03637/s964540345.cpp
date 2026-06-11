#include <bits/stdc++.h>
#include <math.h>
using namespace std;

double f(double x){
  if(x < 0){x *= (-1);}
  return x;
}

int main(){
  int n;
  cin >> n;
  int a = 0;
  int b = 0;
  int c = 0;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    if(x % 4 == 0){a++;}
    else if(x % 2 == 0){b++;}
    else{c++;}
  }
  if(n % 2 == 0){
    if(a >= c || c == 0){cout << "Yes" << endl;}
    else{cout << "No" << endl;}
  }
  else{
    if(b == 0){
      if(a >= c - 1){cout << "Yes" << endl;}
      else{cout << "No" << endl;}
    }
    else{
      if(a >= c){cout << "Yes" << endl;}
      else{cout << "No" << endl;}
    }
  }
}       