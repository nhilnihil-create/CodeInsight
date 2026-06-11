#include <bits/stdc++.h>

#define pb push_back
#define For(i, j, k) for(int i = j; i <= k; i++)

using namespace std;

const int N = 1e5 + 10;

int n, m;

int delt[N], A[N];
vector<int> del[N];

typedef long long LL;

int main(){

	scanf("%d%d", &n, &m);

	LL origin = 0;
	For(i, 1, n) scanf("%d", &A[i]);
	For(i, 2, n) origin += (A[i] - A[i - 1] + m) % m;

	int tot = 0;
	LL sum = 0;

	For(i, 2, n) if((A[i] - A[i - 1] + m) % m > 1){
		int l = A[i - 1] % m + 1, r = A[i];

		delt[l]++;
		if(l <= r) del[r].pb(l);
		else{
			del[r].pb(l - m);
			++tot, sum += l - m;
		}
	}

	LL mx = 0;
	For(i, 1, m){
		tot += delt[i], sum += 1ll * delt[i] * i;
		mx = max(mx, 1ll * tot * i - sum);
		for(int l : del[i]) --tot, sum -= l;
	}
	printf("%lld\n", origin - mx);

	return 0;
}