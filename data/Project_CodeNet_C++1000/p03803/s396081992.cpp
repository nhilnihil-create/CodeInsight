#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <string>
using namespace std;
int main(void){
  int a,b;
  cin>>a>>b;
  if(a==b){
    cout<<"Draw"<<endl;
  }else if(a==1){
    cout<<"Alice"<<endl;
  }else if(b==1){
    cout<<"Bob"<<endl;
  }else if(a>b){
    cout<<"Alice"<<endl;
  }else{
    cout<<"Bob"<<endl;
  }
}