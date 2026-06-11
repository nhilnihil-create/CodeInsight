#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int A, B, C;
	cin >> A >> B >> C;
	for (int i = 1; i < B; i++) {
		int AA = A*i;
		if (AA % B == C) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
