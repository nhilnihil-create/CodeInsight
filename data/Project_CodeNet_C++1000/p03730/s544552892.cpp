#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){return b ? gcd(b,a%b):a;}

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int x = gcd(a,b);
  if(c%x == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}