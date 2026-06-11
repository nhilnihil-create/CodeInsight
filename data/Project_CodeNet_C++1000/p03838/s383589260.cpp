#include <iostream>
using namespace std;

int main(){
  int x, y;
  cin >> x >> y;
  if(x<y){
    if(x<0 && 0<y){
      if(-x<y){
        cout << x+y+1 << endl;
      }else if(-x>y){
        cout << -y-x+1 << endl;
      }else{
        cout << 1 << endl; 
      }
    }else{
      cout << y-x << endl;
    }
  }else{
    if(y<0 && 0<x){
      if(-y<x){
        cout << x+y+1 << endl;
      }else if(-y>x){
        cout << -y-x+1 << endl;
      }else{
        cout << 1 << endl; 
      }
    }else{
      if(x==0){
        cout << -y+1 << endl;
      }else if(y==0){
        cout << x+1 << endl;
      }else{
      	cout << (-y)-(-x)+2 << endl;
      }
    }
  }
  return 0;
}
  
