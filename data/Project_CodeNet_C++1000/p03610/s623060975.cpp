#include<iostream>
using namespace std;
int main(){
  string ss;
  cin >> ss;
  string s = "";
  for (int i=0; i<ss.length(); i+=2){
    s+=ss[i];
  }
  cout << s << endl;
}