#include <iostream>

using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b;
  c = 0;
  if(a%3==0)c=1;
  if(b%3==0)c=1;
  if((a+b)%3==0)c=1;
  if(c)cout << "Possible";
  else cout << "Impossible";
 
}
