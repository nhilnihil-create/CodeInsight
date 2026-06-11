#include <bits/stdc++.h>
#define LL long long
#define PII pair<int,int>
using namespace std;
const int MAXN = 100005;
const int INF = (LL)1e9 + 5;
const LL MOD = 998244353;

int N, M, a[MAXN];
LL st[MAXN], ed[MAXN], sub[MAXN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	LL sum = 0, num = 0, cur = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		a[i]--;
		if (i > 0) {
			int d = a[i] < a[i - 1] ? M - (a[i - 1] - a[i]) : a[i] - a[i - 1];
			st[a[i - 1]]++;
			ed[a[i]]++;
			sub[a[i]] += d;
			sum += d;
			
			if (a[i] < a[i - 1]) {
				num++;
				cur += M - a[i - 1];
			}
		}
	}
	
	LL maxp = 0;
	for (int i = 0; i < M; i++) {
		maxp = max(maxp, cur - num);
//		cout << "At " << i << " -> " << cur << "\n";
		
		num += st[i];
		num -= ed[i];
		cur -= sub[i];
		cur += num;
	}
	
	cout << sum - maxp << "\n";
	
	return 0;
}
