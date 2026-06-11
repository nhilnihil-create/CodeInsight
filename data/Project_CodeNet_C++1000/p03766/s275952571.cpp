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

	int mod = 1e9 + 7;
	int kotae = 0;
	ll kazu = 1;
	int kari = 0;
	int imos[1000010] = {};
	int sq = 1ll * (N - 1) * (N - 1) % mod;
	rep1(i, N - 1) {
		kari = (kari + *(imos + i)) % mod;
		kazu = (kazu + kari) % mod;
		kotae = (kotae + kazu * sq) % mod;
		imos[i + 3] = kazu;
		if (i + 3 > N) kotae = (kotae + kazu * (N - 1)) % mod;
		else kotae = (kotae + kazu * (i + 1)) % mod;
	}
	kazu = (kazu + kari + *(imos + N)) % mod;
	kotae += N * kazu % mod;

	co(kotae % mod);
	
	Would you please return 0;
}