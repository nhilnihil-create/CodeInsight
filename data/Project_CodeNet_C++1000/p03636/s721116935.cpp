#include <iostream>
#include <string>
using namespace std;

int main(){
  string data;
  cin>>data;
  
  cout<<data.front()<<data.size()-2<<data.back();
}