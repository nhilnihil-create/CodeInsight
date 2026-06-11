#include<bits/stdc++.h>
using namespace std;

int main(){
  int x,a,b;
  cin >> x >> a >> b;
  
  if(a-b<0){
  	if(abs(a-b)>x){
      cout << "dangerous";
    }else{
      cout << "safe";
    }
  }else{
  	cout << "delicious";
  }

  return 0;
}