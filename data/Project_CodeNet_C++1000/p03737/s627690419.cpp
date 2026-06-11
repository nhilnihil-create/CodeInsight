#include <bits/stdc++.h>
using namespace std;

int main(){
  string a,b,c;
  cin >> a >> b >> c;
  int A=a.at(0);
  int B=b.at(0);
  int C=c.at(0);
  cout << char(A-32) << char(B-32) << char(C-32) << endl;
}
