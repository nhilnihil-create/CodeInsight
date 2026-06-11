#include <iostream>
#include <string>
using namespace std;

int main(){
  string s,sout="";
  cin >> s;
  for(auto itr=s.begin();itr<s.end();itr+=2)
    sout+=(*itr);
  cout << sout << endl;
}