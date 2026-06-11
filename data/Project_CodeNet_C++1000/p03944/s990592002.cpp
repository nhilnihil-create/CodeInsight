#include <iostream>
using namespace std;

int main(){
  int x0,y0,x1,y1;
  x0=0;
  y0=0;
  int N;
  int x,y,a;
  int S;
  cin >> x1 >> y1 >> N;
  for (int i=0; i<N; i++){
    cin >> x>>y>>a;
    switch (a){
      case 1:
        if(x>x0) x0=x;
        break;
      case 2:
        if(x<x1) x1=x;
        break;
      case 3:
        if(y>y0) y0=y;
        break;
      case 4:
        if(y<y1) y1=y;
        
        break;
    }
  }
  S=(x1-x0)*(y1-y0);
  if((x1-x0)<=0 || (y1-y0)<=0){
    cout << 0<< endl;
  }else{
    cout << S<<endl;
  }
}
       
      