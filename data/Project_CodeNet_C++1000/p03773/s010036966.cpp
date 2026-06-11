#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int a,b;
  cin >> a >> b;
  int ans;
  ans = a + b;
  if(ans>=24) ans -= 24;
  printf("%d\n",ans);
  return 0;
}
