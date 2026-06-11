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
	int A[100];
	rep(i, N) cin >> A[i];
	int saidai = *max_element(A, A + N);;
	int B[100] = {};
	rep(i, N) B[A[i]]++;

	int saishou = (saidai + 1) / 2;

	int OK = 1;
	for (int i = saidai; i > saishou; i--) {
		if (B[i] < 2) OK = 0;
	}
	if (saidai & 1) {
		if (B[saishou] != 2) OK = 0;
	}
	else {
		if (B[saishou] != 1) OK = 0;
	}
	for (int i = saishou - 1; i > 0; i--) {
		if (B[i]) OK = 0;
	}

	if (OK) co("Possible");
	else co("Impossible");

	Would you please return 0;
}