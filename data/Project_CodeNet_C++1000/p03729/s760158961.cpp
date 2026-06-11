#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	string A, B, C;
	cin >> A >> B >> C;
	if(A[A.size() - 1] == B[0] && B[B.size() - 1] == C[0])
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
