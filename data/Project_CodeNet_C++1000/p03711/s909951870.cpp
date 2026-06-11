#include <iostream>
using namespace std;

int main(void){
  int x,y;
  cin>>x>>y;
  
  /*group1={1,3,5,7,8,10,12}
  	group2={4,6,9,11}
    group3={2}
  */
  int group[12]={1,3,1,2,1,2,1,1,2,1,2,1};
  (group[x-1]==group[y-1])?cout<<"Yes":cout<<"No";
  
  return 0;
}