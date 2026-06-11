#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<list>
#include<set>
#include<string>
using namespace std;
int gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}
struct UnionFind {
	vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

	UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
		for (int i = 0; i < N; i++) par[i] = i;
	}

	int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(int x, int y) { // xとyの木を併合
		int rx = root(x); //xの根をrx
		int ry = root(y); //yの根をry
		if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
		par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
	}

	bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
};
typedef long long ll;

const ll M = 1000000007;

vector<ll> fac(300001); //n!(mod M)
vector<ll> ifac(300001); //k!^{M-2} (mod M)

ll mpow(ll x, ll n) {
	ll ans = 1;
	while (n != 0) {
		if (n & 1) ans = ans * x % M;
		x = x * x % M;
		n = n >> 1;
	}
	return ans;
}
ll comb(ll a, ll b) {
	if (a == 0 && b == 0)return 1;
	if (a < b || a < 0)return 0;
	ll tmp = ifac[a - b] * ifac[b] % M;
	return tmp * fac[a] % M;
}
int compare(string a, string b) {
	int i;
	for (i = 0; i < a[i] != '\0'; i++) {
		if (b[i] == '\0')
			return -1;
		else if (a[i] < b[i])
			return 1;
		else if (a[i] > b[i])
			return -1;
	}
	if (b[i] != '\0')
		return 1;
	else
		return 0;
}
int main() {
	int n, i, j, p[111111],flag,q1,q2;
	char s[111111];
	cin >> n >> s;
	for (j = 0; j < 4; j++) {
		flag = 1;
		if (j == 0) {
			p[0] = 0;
			p[1] = 0;
		}
		if (j == 1) {
			p[0] = 1;
			p[1] = 0;
		}
		if (j == 2) {
			p[0] = 0;
			p[1] = 1;
		}
		if (j == 3) {
			p[0] = 1;
			p[1] = 1;
		}
		for (i = 1; i < n - 1; i++) {
			q1 = (p[i - 1] + p[i]) % 2;
			if (s[i] == 'o')
				q2 = 0;
			else
				q2 = 1;
			if (q1 == q2)
				p[i + 1] = 0;
			else
				p[i + 1] = 1;
		}
		q1 = (p[n - 2] + p[n - 1] + p[0]) % 2;
		if (s[n-1] == 'o')
			q2 = 0;
		else
			q2 = 1;
		if (q1 != q2)
			flag--;
		q1 = (p[n - 1] + p[1] + p[0]) % 2;
		if (s[0] == 'o')
			q2 = 0;
		else
			q2 = 1;
		if (q1 != q2)
			flag--;
		if (flag == 1) {
			for (i = 0; i < n; i++) {
				if (p[i] == 0)
					cout << "S";
				else
					cout << "W";
			}
			cout << endl;
			return 0;
		}
	}
	cout << "-1" << endl;;
}