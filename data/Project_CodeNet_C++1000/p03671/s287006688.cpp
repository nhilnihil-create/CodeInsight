#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int kingaku[3];

	kingaku[0] = a + b;
	kingaku[1] = a + c;
	kingaku[2] = b + c;

	int ans = min({ kingaku[0],kingaku[1],kingaku[2] });

	cout << ans << endl;
}