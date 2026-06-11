#include <iostream>
using namespace std;

int n, p[100009], cnt; bool v[100009];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		if (p[i] == i) v[i] = true;
	}
	int s = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (v[i] == true) s++;
		else { 
			cnt += (s + 1) / 2;
			s = 0;
		}
	}
	cout << cnt << endl;
	return 0;
}