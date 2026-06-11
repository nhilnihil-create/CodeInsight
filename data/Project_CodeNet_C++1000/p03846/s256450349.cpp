#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	map<int,int> M;

	for(int i = 0; i < N; i++){
		int x;
		cin >> x;
		M[x]++;
	}

	bool ok = 1;

	if(N & 1){
		for(auto x : M){
			ok &= (x.s == 2 || (x.f == 0 && x.s == 1));
		}
	}
	else{
		for(auto x : M){
			ok &= (x.s == 2 || (x.f == 1 && x.s == 1));
		}
	}

	if(!ok) cout << 0 << endl;
	else{
		ll ans = 1;
		for(int i = 0; i < N/2; i++) ans = (ans * 2) % MOD;
		cout << ans << endl;
	}

	return 0;
}
