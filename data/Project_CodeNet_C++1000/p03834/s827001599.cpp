#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  string s;
  cin>>s;
  for(int i=0;i<19;i++){
    if(i!=5 && i!=13){
      cout<<s[i];
    }
    else{
      cout<<" ";
    }
  }
  cout<<"\n";
  return 0;
}