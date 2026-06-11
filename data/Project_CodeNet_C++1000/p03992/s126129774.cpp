#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, t, u;
  	cin >> s;
  	t = s.substr(0, 4);
  	u = s.substr(4, 8);
  
  	cout << t << " " << u << endl;
  	return 0;
}