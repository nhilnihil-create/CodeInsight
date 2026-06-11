#include<bits/stdc++.h>
using namespace std;

int main(){
  long long w,a,b;
  cin >> w >> a >> b;
  if(w >= abs(a-b)) cout << 0 << endl;
  else cout << abs(w - abs(a-b)) << endl;
}