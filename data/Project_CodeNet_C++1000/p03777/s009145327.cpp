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
  char a,b;
  cin>>a>>b;
  if(a=='H'){
    cout<<b<<endl;
  }else{
    if(b=='H'){
      cout<<'D'<<endl;
    }else{
      cout<<'H'<<endl;
    }
  }
}