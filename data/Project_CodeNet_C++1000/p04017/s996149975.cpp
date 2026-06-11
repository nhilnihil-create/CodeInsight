#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 100005;
const int LGN = 18;
int x[N], nxt[N][LGN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>x[i];
	}
	int l; cin>>l;
	for(int i = 1; i <= n; i++){
		nxt[i][0] = upper_bound(x + 1, x + n + 1, x[i] + l) - x - 1;
	}
	for(int k = 1; k < LGN; k++){
		for(int i = 1; i <= n; i++){
			nxt[i][k] = nxt[nxt[i][k - 1]][k - 1];
		}
	}
	int q; cin>>q;
	while(q--){
		int a, b;
		cin>>a>>b;
		if(a > b)swap(a, b);
		int ans = 1;
		for(int i = LGN - 1; i >= 0; i--){
			if(nxt[a][i] < b){
				ans += (1<<i);
				a = nxt[a][i];
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}