#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < w + 2; i++) {
		cout << '#';
	}
	cout << endl;
	for (int i = 0; i < h; i++) {
		cout << '#' << s[i] << '#' << endl;
	}
	for (int i = 0; i < w + 2; i++) {
		cout << '#';
	}
}