#include<iostream> 

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	rep(i, 3) {
		cin >> s;
		cout << s.at(0);
	}
	cout << "\n";
	
	return 0;
}