#include <iostream>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  if(a==1) a=9999;
  if(b==1) b=9999;
  if(a>b)cout << "Alice";
  if(a<b)cout << "Bob";
  if(a==b)cout << "Draw";
}
