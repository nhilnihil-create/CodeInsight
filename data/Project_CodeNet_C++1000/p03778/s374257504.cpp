#include<bits/stdc++.h>
using namespace std;
int main(){
  int w,a,b;
  cin >> w >> a >> b;
  if(a+w<b)cout << b-a-w;
  else if(b+w<a)cout << a-b-w;
  else cout << 0;
}
