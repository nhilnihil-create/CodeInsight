#include<bits/stdc++.h>
using namespace std;

int main(){
  long long a,b;
  cin >> a >> b;
  long long ans = min(a, b / 2);
  b -= min(a, b / 2) * 2;
  ans += b / 4;
  cout << ans << endl;
}