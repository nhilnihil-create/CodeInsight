#include <iostream>
#include <string>
using namespace std;

int main(){
  string data;
  cin>>data;
  for(int i=0;i<data.size();i+=2){
    cout<<data[i];
  }
}