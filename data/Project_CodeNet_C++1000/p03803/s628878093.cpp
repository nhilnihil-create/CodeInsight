#include<iostream>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  if(a==b) cout << "Draw" << endl;
  else if( (a>b && b != 1) || a==1) cout << "Alice" << endl;
  else cout << "Bob" << endl;
}
