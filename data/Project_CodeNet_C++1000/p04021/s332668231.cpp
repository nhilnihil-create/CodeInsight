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

int n, a[N], num[N];

bool cmp(int x, int y){
	return a[x] < a[y];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {cin >> a[i]; num[i] = i;}
	sort(num + 1, num + n + 1, cmp);
	for (int i = 1; i <= n; i++) a[num[i]] = i;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		if (i % 2 == 1 && a[i] % 2 != 1) ans ++;
	}
	cout << ans;









	return 0;
}
