#include<bits/stdc++.h>
using namespace std;
void bell(int a,int b, int c){
    if(a==b && a==c){
        cout<<(a+b)<<endl;
    }
    else{
       int x,y,z;
       x=a+b;
       y=a+c;
       z=b+c;
       if(x<y && x<z){
          cout<<x<<endl;
       }
      else if(y<x && y<z){
        cout<<y<<endl;
       }
       else if(z<x && z<y){
        cout<<z<<endl;
       }
    }
}
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  bell(a,b,c);
  return 0;
}
