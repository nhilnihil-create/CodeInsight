#include<iostream>
 
using namespace std;
 
int main(){
  int n;
  cin>>n;
  if(n/100==(n%100)%10){
    cout<<"Yes";
  }else {
    cout<<"No";
  }
  return 0;
}