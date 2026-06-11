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
  long long int x;
  cin>>x;
  long long int pre=x/11;
  pre*=2;
  if(x%11!=0){
  if(x%11<=6){
    pre+=1;
  }else{
    pre+=2;
  }
  }
  cout<<pre<<endl;
}