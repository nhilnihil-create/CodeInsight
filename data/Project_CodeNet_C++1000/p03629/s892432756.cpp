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


	string S;
	cin >> S;

	int N = S.size();
	vector<int> V;
	V.pb(N);
	int kazu = 0;
	int A[26] = {};
	for (int i = N - 1; i >= 0; i--) {
		A[S[i] - 'a']++;
		int OK = 0;
		rep(j, 26) if (!A[j]) OK = 1;
		if (!OK) {
			kazu++;
			V.pb(i);
			rep(j, 26) A[j] = 0;
		}
	}

	rep(j, 26) A[j] = 0;
	vector<char> kotae;
	int flag = 0;
	int nai = 0;
	rep(i, N) {
		if (i == V[kazu]) {
			rep(j, 26) if (!A[j]) {
				nai = j;
				break;
			}
			kotae.pb('a' + nai);
			kazu--;
			flag = 1;
		}
		if (flag && S[i] == 'a' + nai) {
			rep(j, 26) A[j] = 0;
			flag = 0;
		}
		else if (flag == 0) {
			A[S[i] - 'a']++;
		}
	}
	rep(j, 26) if (!A[j]) {
		nai = j;
		break;
	}
	kotae.pb('a' + nai);

	rep(i, kotae.size()) cout << kotae[i];
	cout << endl;

	Would you please return 0;
}