#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

 
int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int ans = a + b;
  if(ans>b+c) ans = b+c;
  if(ans>a+c) ans = a+c;
  cout << ans << endl;
  return 0;
}
