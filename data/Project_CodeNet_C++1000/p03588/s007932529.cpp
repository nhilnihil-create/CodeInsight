#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ans=2000000000;
  cin >> n;
  int a, b;
  for(int i=0; i<n; i++){
    cin >> a >> b;
    if(a+b<ans)ans=a+b;
  }
  cout << ans;
  return 0;
}