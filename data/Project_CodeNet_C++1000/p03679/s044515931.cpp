#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(c<=b)cout << "delicious";
  else if((a+b)>=c)cout << "safe";
  else cout << "dangerous";
}
