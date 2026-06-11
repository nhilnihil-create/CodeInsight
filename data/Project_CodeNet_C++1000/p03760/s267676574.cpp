#include<iostream>
#include<string>
using namespace std;
int main(){

  string O,E;
  cin>>O>>E;
  for(size_t i=0;i<=O.length()+E.length()-1;i++){
  
    if(i%2==0){
    
      cout<<O[i/2];
    }
    else{
    
      cout<<E[i/2];
    }
  }
  return 0;
}