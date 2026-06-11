#include <iostream>
#include <string>
using namespace std;

int main(){
  	string s;
  	cin >> s;
  	int f = s.find_first_of('A');
  	int l = s.find_last_of('Z');
  	cout << l-f+1 << endl;
}
