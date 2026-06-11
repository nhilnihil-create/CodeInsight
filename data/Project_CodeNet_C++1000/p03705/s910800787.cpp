#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, a, b;
  cin >> n >> a >> b;
  
  long long ans = max((long long)0, b*(n-2) - a*(n-2) + 1);
  
  cout << ans << endl;
}