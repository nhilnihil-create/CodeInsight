#include<iostream>
using namespace std;
 
main(){
  long long s_n,c_n,r=0;
  cin>>s_n>>c_n;
  
  long long s_n_2 = s_n*2;
  
  
  if( s_n_2<= c_n ){
    r += s_n;
    c_n -= s_n_2;
    s_n = 0;
  }
  else{
    r += c_n/2;
    s_n -= r;
    c_n -= 2*c_n;
  }
  
  if (c_n>3){
    r += c_n/4;
  } 
  cout<< r <<endl;
  return 0;
}