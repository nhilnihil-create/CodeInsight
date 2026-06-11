#include <iostream>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  if(a>c) cout << "No";
  else if(b<c) cout << "No";
  else cout << "Yes";
}