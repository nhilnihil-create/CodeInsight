#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

typedef double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9 + 7;

int main(){ _

	ll N;
	cin >> N;
	
	vector<int> table((int)1e3 + 10, 0);

	for(int i = 2; i <= N; i++){
	
		int x = i;
		for(int j = 2; j*j <= x; j++){
			while(!(x % j)){
				table[j]++;
				x/=j;
			}
		}
		if(x != 1) table[x]++;
	
	}

	ll ans = 1;
	for(int i = 0; i < (1e3 + 10); i++){
		if(!table[i]) continue;
		ans = (ans * (table[i] + 1)) % MOD;
	}

	cout << ans << endl;

	return 0;
}
