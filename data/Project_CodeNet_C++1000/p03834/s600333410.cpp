#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

int main(){
  string data;
  string ss;
  cin>>ss;
  istringstream s(ss);
  while(getline(s,data,',')){
    cout<<data<<' ';
  }
  
}

