#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b){
  return b ? gcd(b, a%b) : a;
}

int main(){
  long long N, X; cin >> N >> X;
  if(X>N/2){
    X=N-X;
  }
  long long ans=gcd(X, N)*(N/gcd(X, N)-1)*3;
  cout << ans << endl;
}