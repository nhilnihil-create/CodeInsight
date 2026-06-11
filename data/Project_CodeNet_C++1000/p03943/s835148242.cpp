#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b,c;
  cin>>a>>b>>c;
  if(a+b==c || b+c==a || c+a==b){
    cout<<"Yes"<<"\n";
  }
  else{
    cout<<"No"<<"\n";
  }
  return 0;
}