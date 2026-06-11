#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i <= (ll)(n); ++i)
#define MAX 500010
#define MOD 1000000007
typedef long long  ll;

using namespace std;

ll ans;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;
	cin >> S;

	rep(i,S.size()){
		if(i==5 || i==13) cout << " ";
		else cout << S[i];
	}

	cout << endl;

	return 0;
}
