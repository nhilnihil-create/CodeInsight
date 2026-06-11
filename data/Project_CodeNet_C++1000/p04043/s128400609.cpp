#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c; cin >> a >> b >> c;
  if(b < c)swap(b,c);
  if(a < b)swap(a,b);
  if(make_tuple(a,b,c) == make_tuple(7,5,5))cout << "YES" << endl;
  else cout << "NO" << endl;
}