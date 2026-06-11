#include <iostream>
using namespace std;
int main(void){
  
  int n,k,x,y;
  
    cin>> n >> k >> x >>y ;
  
  if (n<=k){
    cout << n*x << endl;
  }
  if(n>k){
    cout << x*k + (n-k)*y << endl;
  }
  
  
}