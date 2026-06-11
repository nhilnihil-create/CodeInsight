#include<iostream>
using namespace std;

bool alice[105],bob[105];

int main() {
	int a, b, c, d; cin >> a >> b >> c >> d;

	for (int i = a; i <= b; i++) {
		alice[i] = true;		
	}
	for (int i = c; i <= d; i++) {
		bob[i] = true;
	}
	int ans = 0;
	for (int i = 0; i <= 100; i++) {
		if (alice[i] && bob[i])ans++;
	}
	cout << (ans?ans-1:0) << endl;

	return 0;
}