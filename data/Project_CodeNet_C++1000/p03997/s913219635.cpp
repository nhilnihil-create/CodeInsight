#include <iostream>
using namespace std;

int cal(int a,int b,int h){
	int d ;
  d = (a + b)*h/2;
    return d;
}

int main(){
  int a,b,h;
  
  cin >> a;
  cin >> b;
  cin >> h;
  
  cout << cal(a,b,h);
  return 0;
}