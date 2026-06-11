#include<iostream> 

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int a, b;
	char s;
	cin >> a >> s >> b;
	if (s == '+') {
		cout << a + b << endl;

	}if (s == '-') {
		cout << a - b << endl;
	}
	
	return 0;
}