#include <bits/stdc++.h>
using namespace std;
  

int main() {
  int n,k;
  
  cin >> n >> k;
  
  int jou = n-1;
  
  int total = k*pow(k-1,jou);
  
  cout << total;
}
