#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define putchar putchar_unlocked
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	
	char S[200001]; 
	int N = fread(S, 1, 200001, stdin);
	if (S[N - 1] < 'a' || S[N - 1] > 'z') N--;

	vector<int> V;
	V.pb(N);
	int kazu = 0;
	int A = 0;
	for (int i = N - 1; i >= 0; i--) {
		A |= 1 << S[i] - 'a';
		if (A == 67108863) {
			kazu++;
			V.pb(i);
			A = 0;
		}
	}

	A = 0;
	vector<char> kotae;
	int flag = 0;
	int nai = 0;
	rep(i, N) {
		if (i == V[kazu]) {
			rep(j, 26) if (!(A >> j & 1)) {
				nai = j;
				break;
			}
			kotae.pb('a' + nai);
			kazu--;
			flag = 1;
		}
		if (flag) {
			if (S[i] == 'a' + nai) {
				A = 0;
				flag = 0;
			}
		}
		else if (flag == 0) {
			A |= 1 << S[i] - 'a';
		}
	}
	rep(j, 26) if (!(A >> j & 1)) {
		nai = j;
		break;
	}
	kotae.pb('a' + nai);

	rep(i, kotae.size()) putchar(kotae[i]);
	putchar('\n');

	Would you please return 0;
}