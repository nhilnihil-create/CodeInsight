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

	int N, x;
	cin >> N >> x;

	vector<int> V(N);
	for(auto &i : V)  cin >> i;

	ll ans = 0;

	for(int i = 1; i < N; i++){
		int need = V[i] + V[i-1] - x;
		if(need <= 0) continue;

		ans += need;

		int to = min(need,V[i]);
		V[i] -= to;
		need -= to;

	}

	cout << ans << endl;

	return 0;
}
