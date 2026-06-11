#include<iostream>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  cout<<(a%3&&b%3&&(a+b)%3?"Impossible":"Possible")<<endl;
}
