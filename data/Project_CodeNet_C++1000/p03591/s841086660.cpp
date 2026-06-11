#include<iostream>
#include<string>
using namespace std;
int main(){
  string s;cin >> s;
  if (s.size() < 4) cout << "No" << endl;
  else cout << ((s.substr(0,4) == "YAKI") ? "Yes":"No") << endl;
}