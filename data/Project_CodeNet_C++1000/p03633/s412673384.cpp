#include<bits/stdc++.h>
using namespace std;

long long gcd(const long long a, const long long b){ 
  return (a % b) ? gcd(b, a % b) : b; 
}
long long lcm(const long long a, const long long b){
  long long re = a / gcd(a, b) * b;
  return re;
}

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  long long ans = a[0];
  for(int i = 1; i < n; i++) ans = lcm(ans, a[i]);
  cout << ans << endl;
}