#include<iostream>
using namespace std;
#define df 0

int main(){
  if(df) printf("*debug mode*\n");
  string s; cin >>s;
  int a=s.size(); a-=2;
  if(*(s.begin())==*(s.end()-1)) a--;
  
  printf("%s\n",a%2?"First":"Second");
}

/// confirm df==0 ///