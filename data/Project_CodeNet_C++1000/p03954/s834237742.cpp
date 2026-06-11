#include <bits/stdc++.h>

#define fio() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef pair<pi, ll> pii;

const ll mod = 1e9 + 7;
const ll maxn = 2e5 + 6;
const ll N = 1e2 + 2;
const ll inf = 1e12;
const ld eps = 1e-6;

ll n, k, arr[maxn], col[maxn];

// if ans > x

void print() {
	for (int i = 0; i < k; i++)
		cout << col[i] << " ";
	cout << endl;	
}

bool solve(ll x) { 
	for (int i = 0; i < k; i++) {
		if (arr[i] > x)
			col[i] = 1;
		else
			col[i] = 0;
	}
//	print();
	for (int i = 1; i < n; i++) {
		if (col[n - i - 1] == col[n - i]) 
			return col[n - i];
		if (col[n + i - 1] == col[n + i - 2]) 
			return col[n + i - 1];
	}
	return col[0];
}

int main() {
	fio();
	cin >> n;
	k = 2 * n - 1;
	for (int i = 0; i < k; i++) 
		cin >> arr[i];	
	ll L = 0, R = k - 1, M;
	while (L < R) {
		//cout << L << " " << R << endl;
		M = (L + R) / 2;
		if (solve(M)) 
			L = M + 1;
		else
			R = M;
	}
	cout << L << endl;
	return 0;
}
