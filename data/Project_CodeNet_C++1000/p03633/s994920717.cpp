#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
  if(b == 0) return a;
  return gcd(b, a%b);
}

int main(){
  int n; cin >> n;
  long long ans;
  cin >> ans;
  for(int i = 1; i < n; i++){
    long long a; cin >> a;
    ans = a / gcd(ans, a) * ans;
  }
  cout << ans << endl;
}
    