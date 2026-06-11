#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t a,b,c;
  cin >> a >> b >> c;
  if(a%2==1&&b%2==1&&c%2==1)
    cout << min({a*b,b*c,c*a}) << endl;
  else
    cout << 0 << endl;
  return 0;
}