#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k, x, y, sum=0;
  cin >> n >> k >> x >> y;
  if(n>k)sum = (n-k)*y + k*x;
  else if(n==k)sum = k*x;
  else sum = n*x;
  cout << sum;
}