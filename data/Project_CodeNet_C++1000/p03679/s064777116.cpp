#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(c-b<=0)cout << "delicious";
  else if(c-b<=a)cout << "safe";
  else cout << "dangerous";
}
