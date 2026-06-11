#include <bits/stdc++.h>
using namespace std;

int main(){
  int x,y;
  cin >> x>>y;
  int A=0,B=0;
  if(x==(-y)){
    cout<<1<<endl;
    return 0;
  }
  if(((x>0)&&(y>0))&&(x<y)){
    cout<<y-x<<endl;
    return 0;
  }
  if(((x>0)&&(y>0))&&(x>y)){
    cout<<abs(y-x)+2<<endl;
    return 0;
  }  
  
  if((x<0)&&(y>0)){
    cout<<abs(y-abs(x))+1<<endl;
    return 0;
  }  
  if((x<0)&&(y==0)){
    cout<<abs(x)<<endl;
    return 0;
  }
  if((x>0)&&(y==0)){
    cout<<abs(x)+1<<endl;
    return 0;
  }
  
  if((x==0)&(y<0)){
    cout<<abs(y)+1<<endl;
    return 0;
  }
  if((x==0)&(y>0)){
    cout<<y<<endl;
    return 0;
  }
  if((x>0)&&(y<0)){
    cout<<abs(abs(y)-abs(x))+1<<endl;
    return 0;
  }  
  
  if(((x<0)&&(y<0))&&(abs(x)<abs(y))){
    cout<<abs(abs(y)-abs(x))+2<<endl;
    return 0;
  }  
  if(((x<0)&&(y<0))&&(abs(x)>abs(y))){
    cout<<abs(abs(y)-abs(x))<<endl;
    return 0;
  }  
  
  return 0;
}

    
    