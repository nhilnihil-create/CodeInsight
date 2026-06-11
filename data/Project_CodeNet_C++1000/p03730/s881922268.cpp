#include<bits/stdc++.h>
using namespace std;

int a, b, c;

int gcd(int a, int b){
  if(a%b == 0) return b;
  else return gcd(b, a%b);
}

int main(void){
  cin >> a >> b >> c;
  if(c%gcd(a, b) == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
