#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  string result="No";
  while(n>0){
    if(n%10==9){
      result="Yes";
      break;
    }
    n/=10;
  }
  cout<<result;
}