#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  cin >>a>>b>>c>>d;
  
  if(b>=c && d>=b){
    if(a<=c){
      cout << b-c <<endl;
    }
    else{
      cout << b-a <<endl;
    }
  }
  else if(a<=d && d<=b){
    if(a>=c){
      cout << d-a <<endl;
    }
    else{
      cout << d-c <<endl;
    }
  }
  else{
    cout << 0 <<endl;
  }
}

