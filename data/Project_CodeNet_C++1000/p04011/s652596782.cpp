#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k,x,y; cin >> n >> k >> x >> y;
  int charge = 0;
  if (k >= n){
    charge = x * n;
  }
  else{
    int charge1 = x * k;
    int charge2 = (n - k) * y;
    charge = charge1 + charge2;
  }
  cout << charge;
}