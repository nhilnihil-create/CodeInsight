#include<iostream>
#include<string>
using namespace std;

int main(){
  string s;
  cin >> s;
  int num=0;
  for(int i=1;i<s.size()-1;i++){
    num++;
  }
  
  cout << s.at(0) << num << s.at(s.size()-1) << endl;
}
