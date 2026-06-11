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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N,K;
	cin >> N >> K;

	if(N == 1) {
		cout << K << endl;
		return 0;
	}

	ll ans = 1;
	for(int i = 0; i < N - 1; i++) ans *= (K - 1);
	ans *= K;

	cout << ans << endl;

	return 0;
}
