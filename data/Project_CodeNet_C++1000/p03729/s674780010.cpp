#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
	string a, b, c; cin >> a >> b >> c;
	if (a.back() == b.front() && b.back() == c.front()) {
	    cout << "YES";
	} else {
	    cout << "NO";
	}
	
	return 0;
}
