#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;
	int A = 0, B = 0, AN = 1, BN = 0;
	cin >> A;
	int dame = 0;
	rep(i, N - 1) {
		int a;
		cin >> a;
		if (!B) {
			if (A == a) AN++;
			else if (abs(a - A) == 1) {
				B = a;
				BN++;
				if (A < B) {
					swap(A, B);
					swap(AN, BN);
				}
			}
			else dame = 1;
		}
		else {
			if (A == a) AN++;
			else if (B == a) BN++;
			else dame = 1;
		}
	}

	if (dame) co("No");
	else if (B == 0 && A == N - 1) co("Yes");
	else {
		A -= BN;
		if (A <= 0) co("No");
		else if (A * 2 > AN) co("No");
		else co("Yes");
	}

	Would you please return 0;
}