#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
const int N = 1e5 + 5;
int n, q;
lli l;
lli x[N];
int a[N];
int b[N];

int lastJump[N][20]; //Last index reachable by L*2^(second index) jumps

int solve(int a, int b, int ans) {
	if(a >= b) return ans;

	int x = lower_bound(lastJump[a], lastJump[a]+20, b) - lastJump[a];
	if(x != 0) x--;
	return solve(lastJump[a][x], b, ans + (1<<x));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i=0; i<n; i++) cin >> x[i];

	cin >> l >> q;

	for(int i = 0; i < q; i++) cin >> a[i] >> b[i];

	for(int j=0; j<20; j++) {
		if(j==0) {
			lli jumpL = ((lli)1<<j)*l;
			int k = 0;
			while(k<n && x[k] - x[0] <= jumpL) k++;
			lastJump[0][j] = k-1;
			for(int i=1; i<n; i++) {
				while(k < n && x[k] - x[i] <= jumpL) k++;
				lastJump[i][j] = k-1;
			}
		} else {
			for(int i=0; i<n; i++) {
				lastJump[i][j] = lastJump[lastJump[i][j-1]][j-1];
			}
		}
	}

	for(int i=0; i<q; i++) {
		if(a[i] > b[i]) {
			int tmp = a[i];
			a[i] = b[i];
			b[i] = tmp;
		}
		cout << solve(a[i]-1, b[i]-1, 0) << endl;
	}

	return 0;
}