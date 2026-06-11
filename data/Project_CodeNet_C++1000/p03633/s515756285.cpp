#include <bits/stdc++.h>
using namespace std;

long long gcm(long long a, long long b){
  if(a % b == 0) return b;
  a = a % b;
  return gcm(b, a);
}

long long lcm(long long a, long long b){
  return a / gcm(a, b) * b;
}

int main() {
  int n;
  cin >> n;
  long long ans = 1;
  for(int i = 0; i < n; i++){
    long long k;
    cin >> k;
    ans = lcm(ans, k);
  }
  
  cout << ans << endl;
}