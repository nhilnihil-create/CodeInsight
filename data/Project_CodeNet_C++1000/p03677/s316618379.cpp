#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) (V).begin(),(V).end()
#define MOD 1000000007
#define mod 998244353

ll rw1[100010], rw2[100010];

int main(){
	for (int i = 0;i < 100010;i++)rw1[i] = rw2[i] = 0;
	ll N, M, a, b, ans = 0;
	cin >> N >> M;
	cin >> a;
	for (int i = 1;i < N;i++) {
		cin >> b;
		if (a < b) {
			rw1[a + 1]++;
			rw1[b + 1]--;
			rw2[a + 1]--;
			rw2[b + 1] -= b - a - 1;
			ans += b - a;
		}
		else {
			rw1[1]++;
			rw1[b + 1]--;
			rw2[0] += M - a - 1;
			rw2[b + 1] -= b + (M - a - 1);
			rw1[a + 1]++;
			rw2[a + 1]--;
			ans += M - a + b;
		}
		a = b;
	}
	a = 0;

	for (int i = 1;i <= M;i++)rw1[i] += rw1[i - 1];
	rw2[0] += rw1[0];
	for (int i = 1;i <= M;i++)rw2[i] += rw2[i - 1] + rw1[i];
	for (int i = 1;i <= M;i++)a = max(a, rw2[i]);
	cout << ans - a << endl;
}