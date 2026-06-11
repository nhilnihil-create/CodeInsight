#include<iostream>
using namespace std;
int main(){
  int a, b, c, d;
  while(cin >> a >> b >> c >> d){
    if(a * b > c * d){
      cout << a * b;
    }else{
      cout << c * d;
    }
  }
}
