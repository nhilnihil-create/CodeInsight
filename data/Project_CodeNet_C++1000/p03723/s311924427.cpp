#include<bits/stdc++.h>
using namespace std;
int main() {
	int A, B, C; cin >> A >> B >> C;
	int res = 0;
	if(A % 2 == 0 && A == B && B == C) {
		cout << "-1" << endl;
		return 0;
	}
	while (true)
	{
		if(A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
			cout << res << endl;
			return 0;
		}
		int a = (B + C) / 2;
		int b = (A + C) / 2;
		int c = (A + B) / 2;
		A = a, B = b, C = c;
		res++;
	}
	
	return 0;
}
