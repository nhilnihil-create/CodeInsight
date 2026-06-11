//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimise ("ofast")
#pragma GCC optimise("unroll-loops")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000000000000;
const ll LOG = 25;

int n, a[N], b[N];

bool isval(int x){
	for (int i = 1; i <= n; i++){
		b[i] = (a[i] >= x);
	}
	int L = 0, R = n + 1;
	for (int i = n / 2 + 1; i >= 2; i--){
		if (b[i] == b[i - 1]){
			L = i;
			break;
		}
	}
	for (int i = n / 2 + 1; i < n; i++){
		if (b[i] == b[i + 1]){
			R = i;
			break;
		}
	}
	if (L == 0 && R == n + 1){
		return (b[n / 2 + 1] ^ (((n + 1) / 2 + 1) % 2));
	}
	if (L == 0){
		return b[R];
	}
	if (R == n + 1){
		return b[L];
	}
	if ((n / 2 + 1) - L < R - (n / 2 + 1)){
		return b[L];
	}
	return b[R];
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	n = 2 * n - 1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 1, r = n;
	while (r - l > 1){
		int md = (l + r) >> 1;
		if (isval(md)) l = md;
		else r = md;
	}
	cout << l;










	return 0;
}
