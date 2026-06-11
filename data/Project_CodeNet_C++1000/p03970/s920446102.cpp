#include<iostream>
using namespace std;
int main(void){
  int a=0,b,c;
  string s;
  string t = "CODEFESTIVAL2016";
 cin >> s;
  for(int i = 0;i < s.size();i++){
    if(s.at(i) != t.at(i)){
      a++;
    }
  }
    cout << a;
}