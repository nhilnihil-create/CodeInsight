#include <bits/stdc++.h>
using namespace std;

int main() {
	int x,a,b;
  	cin>>x>>a>>b;
  int al = a-x;
  int bl = b-x;
  
  if(al<0){
    al = -al;
  }
  
  if(bl<0){
    bl = -bl;
  }
  
  
  if(al<bl){
    cout<<"A"<<endl;
  }
  
  else{
    cout<<"B"<<endl;
  }
      
          
}
  