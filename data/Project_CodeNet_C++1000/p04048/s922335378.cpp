#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using namespace std;

long long gcd(long long a,long long b){
  if(b == 0) return a;
  return gcd(b,a%b);
}

int main(){
 long long int a,b;
  cin >> a >> b;
  
  cout <<3*(a-gcd(a,b)) << endl;
}
