#include<iostream>
using namespace std;
int main(){
string a,b; cin >> a >> b;
  a = string(max(0,(int)b.size()-(int)a.size()),'0') + a;
  b = string(max(0,(int)a.size()-(int)b.size()),'0') + b;
  if(a == b)cout << "EQUAL" << endl;
  if(a > b)cout << "GREATER" << endl;
  if(a < b)cout << "LESS" << endl;
}