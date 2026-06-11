#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  string a,b;
  cin>>a>>b;
  if(a==b){
    cout<<"H"<<"\n";
  }
  else{
    cout<<"D"<<"\n";
  }
    return 0;
}