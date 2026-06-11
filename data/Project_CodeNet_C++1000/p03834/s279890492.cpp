#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
  string a;
  cin>>a;
  
  for(int i=0;i<19;i++){
    if(a.at(i)==',')
      a.at(i)=' ';
  }
  cout<<a;
  
  return 0;
}
