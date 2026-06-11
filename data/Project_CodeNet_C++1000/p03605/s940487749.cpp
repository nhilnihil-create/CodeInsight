#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	int a = N / 10;
	int b = N % 10;

	if (a == 9 || b == 9) cout << "Yes" << endl;
	else cout << "No" << endl;
}