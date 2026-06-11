#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int A = a + b,B = b + c,C = a + c;
  cout << min(A,min(B,C)) << endl;
}