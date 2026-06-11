#include<iostream>
using namespace std;
int main(){
  string a,b,c; cin >> a >> b >> c;
  cout<< char(a.at(0) - 32);
  cout<< char(b.at(0) - 32);
  cout<< char(c.at(0) - 32);
}