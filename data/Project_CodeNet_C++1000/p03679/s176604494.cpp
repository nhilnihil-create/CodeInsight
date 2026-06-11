#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int x,a,b;
  cin>>x>>a>>b;
  if(a>=b){
    cout<<"delicious"<<"\n";
  }
  else{
    b-=a;
    if(x<b){
      cout<<"dangerous"<<"\n";
    }
    else{
      cout<<"safe"<<"\n";
    }
  }
  return 0;
}