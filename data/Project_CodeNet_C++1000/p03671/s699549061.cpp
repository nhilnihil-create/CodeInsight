#include <bits/stdc++.h>
using namespace std;
int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	int D = A + B;
	int E = A + C;
	int F = B + C;

	if (D < E&&D < F) {
		cout << D << endl;
	}

	else if (E < D&&E < F) {
		cout << E << endl;
	}

	else {
		cout << F << endl;
	}
}
