#include <iostream>
using namespace std;

int main() {
	string s;
  string ans = "CODEFESTIVAL2016";
  cin >> s;
  int a = 0;
  for(int c = 0;c<16;c++){
	if(s[c] != ans[c]){
		a++;
    }
  }
  cout << a++;
}