#include <iostream>
#include <set>
using namespace std;

int main(void) {

	set<int> s;
	
	for (int i = 0; i < 3; i++) {
		int a;
		cin >> a;
		s.insert(a);
	}
	cout << s.size() << endl;

	return 0;
}