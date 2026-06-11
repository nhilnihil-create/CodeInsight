#include<iostream>
using namespace std; 

int main()
{
  int64_t X,Y ;
  cin>>X>>Y ;
  
  int64_t ans=(X>Y?X-Y:Y-X) ;
  if(ans<=1) cout<<"Brown"<<endl ;
  else cout<<"Alice"<<endl ;
  
  return 0 ;
}
