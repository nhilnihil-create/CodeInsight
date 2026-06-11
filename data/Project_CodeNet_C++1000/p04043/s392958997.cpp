#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  cout << ( max({a,b,c})==7 && ( a + b + c - 7 ) / 2 == 5 ? "YES" : "NO" ) << endl;
}