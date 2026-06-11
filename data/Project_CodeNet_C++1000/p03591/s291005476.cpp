#include <iostream>
#include <string>
using namespace std;
int main(){
  string s;
  cin >> s;
  if(s.size()<4){
    puts("No");
    return 0;
  }else if(s.substr(0,4)=="YAKI"){
    puts("Yes");
  }else{
    puts("No");
  }
  return 0;
}