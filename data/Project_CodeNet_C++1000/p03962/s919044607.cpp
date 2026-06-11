#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);

	int A, B, C; cin >> A >> B >> C;
	if (A != B && B != C && A != C)cout << 3 << endl;
	else if (A == B && B == C && A == C) cout << 1 << endl;
	else cout << 2 << endl;

	return 0;
}

