#include <bits/stdc++.h>
using namespace std;




int main() {

    int64_t x,y;
    cin>>x>>y;

    //x>=0,y>=0,  x=<y -> y-x
    //              x>y  -> x-y+2
    //x<0,y<0,    x=<y  -> abs(x)-abs(y)
    //            x>y    ->abs(y)-abs(x)+2
    // x>=0,y<0   abs(x)<=abs(y)  -> abs(y)-abs(x)+1
    //            abs(x)>abs(y)  ->  abs(x)-abs(y)+1
    // x<0,y>=0   abs(x)<=abs(y) -> abs(y)-abs(x)+1
    //            abs(x)>abs(y)  -> abs(x)-abs(y)+1


    if(x>0&&y==0){
      cout<<x+1<<endl;
    }
    else if(x<0&&y==0){
      cout<<abs(x)<<endl;
    }
    else if(x>=0&&y>=0){
      if(x<=y)
        cout<<y-x<<endl;
      else
        cout<<x-y+2<<endl;
    }else if(x<0&&y<0){
      if(x<=y)
        cout<<abs(x)-abs(y)<<endl;
      else
        cout<<abs(y)-abs(x)+2<<endl;
    }else{
      if(abs(x)<=abs(y))
        cout<<(abs(y)-abs(x)+1)<<endl;
      else
        cout<<(abs(x)-abs(y)+1)<<endl;
    }

	return 0;
}