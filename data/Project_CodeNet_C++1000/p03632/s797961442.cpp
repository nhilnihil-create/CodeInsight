#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d; cin >> a >> b >> c >> d;
  int begin = max(a, c);
  int end = min(b, d);
  if ((end - begin) > 0) cout << end - begin << endl;
  else cout << 0 << endl;
  return 0;
}