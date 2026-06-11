#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c; cin >> a >> b >> c;
  cout << (c == clamp(c,a,b) ? "Yes" : "No") << endl;
}