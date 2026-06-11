#include <bits/stdc++.h>
using namespace std;

int main(){
  long n,k;
  cin >> n >> k;
  long a = __gcd(n,k);
  cout << (n-a)*3 << endl;
}